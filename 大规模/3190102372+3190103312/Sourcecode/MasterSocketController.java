package RegionController.SocketController;

import java.io.*;
import java.net.Socket;
import java.util.Hashtable;
import java.util.Map;

import MasterController.SocketController.BackupInfo;
import MasterController.utils.SocketUtils;
import miniSQL.*;
import miniSQL.CATALOGMANAGER.CatalogManager;
import miniSQL.CATALOGMANAGER.index;
import miniSQL.CATALOGMANAGER.table;
import miniSQL.Interpreter;

import javax.naming.ldap.SortKey;


public class MasterSocketController implements Runnable {
    private Socket socket;
    private BufferedReader input = null;
    private PrintWriter output = null;
    private FileController fileController;
    private boolean isRunning = false;

    public final int SERVER_PORT = 12345;
    public final String MASTER = "192.168.43.53";
    private final String host_ip;
    private Hashtable<String, table> tables;
    private Hashtable<String, index> indices;

    public MasterSocketController(FileController fileController) throws IOException {
        this.socket = new Socket(MASTER, SERVER_PORT);
        CatalogManager.InitialCatalog();
        this.tables = CatalogManager.getTables();
        this.indices = CatalogManager.getIndex();
        input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        output = new PrintWriter(socket.getOutputStream(), true);
        this.fileController = new FileController();
        isRunning = true;
        host_ip = SocketUtils.getHostAddress();
    }

    public void sendToMaster(String modified_info) {
        output.println(modified_info);
    }

    public void sendTableInfoToMaster(String table_info) {
        System.out.println("INFO: sent table_list to master");
        output.println("R1" + table_info);
    }

    public String getMetaInfo() {
        StringBuilder result = new StringBuilder();
        for (Map.Entry<String, table> stringTableEntry : tables.entrySet()) {
            result.append(((Map.Entry) stringTableEntry).getKey()).append(" ");
        }
        return result.toString();
    }
    public void receiveFromMaster() throws IOException {
        String line = null;
        if (socket.isClosed() || socket.isInputShutdown() || socket.isOutputShutdown()) {
            System.out.println("INFO: Socket of master has closed.");
        } else {
            line = input.readLine();
        }
        System.out.println("INFO: Receive From Master: \n" + line);
        if (line != null) {
            if (line.startsWith("M3")) {
                // M3@ip
                if(line.length()==2) return;
                fileController.Connect();
                //String info = line.substring(2);
                String need_transfer_ip = line.split("@")[1];
                fileController.GetOtherRegionFile(BackupInfo.DEFAULT_DIR+File.separatorChar+need_transfer_ip,
                        BackupInfo.DEFAULT_DIR + File.separatorChar + host_ip);
                try {
                    API.Initialize();
                }
                catch (Exception e) {
                    e.printStackTrace();
                }finally {
                    fileController.Close();
                }
                output.println("R3 Complete disaster recovery");
            }
            else if (line.equals("M4")) {
                String tableName = getMetaInfo();
                String[] tableNames = tableName.split(" ");
                for(String table: tableNames) {
                    String tmp_sql = "drop table " + table + " ;";
                    //BufferedReader reader = StringToBufferedReader(tmp_sql);
                    InputStream is = new ByteArrayInputStream(tmp_sql.getBytes());
                    BufferedReader reader = new BufferedReader(new InputStreamReader(is));
                    Interpreter.Parsing(reader);
                    try {
                        API.store();
                        API.Initialize();
                    }
                    catch (Exception e) {
                        e.printStackTrace();
                    }
                }
                output.println("R4 ");
            }
        }
    }

    public void delFile(String fileName) {
        File file = new File(fileName);
        if (file.exists() && file.isFile()) file.delete();
    }

    @Override
    public void run() {
        System.out.println("INFO: Start listening to master...");
        while (isRunning) {
            if (socket.isClosed() || socket.isInputShutdown() || socket.isOutputShutdown()) {
                isRunning = false;
                break;
            }
            try {
                receiveFromMaster();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(100);
            } catch (InterruptedException | NullPointerException e) {
                e.printStackTrace();
            }
        }
    }
}
