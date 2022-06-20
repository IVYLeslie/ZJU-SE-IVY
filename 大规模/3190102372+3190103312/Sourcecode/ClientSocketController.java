package RegionController.SocketController;

import MasterController.SocketController.BackupInfo;
import MasterController.utils.SocketUtils;
import miniSQL.API;
import miniSQL.Interpreter;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashMap;

public class ClientSocketController implements Runnable {
    private ServerSocket serverSocket;
    private MasterSocketController masterSocketController;
    private HashMap<Socket, Thread> clientHashMap;

    public ClientSocketController(int port, MasterSocketController masterSocketController,
                                  FileController fileController) throws IOException {
        this.serverSocket = new ServerSocket(port);
        this.masterSocketController = masterSocketController;
        this.clientHashMap = new HashMap<Socket, Thread>();
    }

    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep(1000);
                Socket socket = serverSocket.accept();
                ClientThreads clientThreads = new ClientThreads(socket, masterSocketController);
                Thread thread = new Thread(clientThreads);
                // 把子线程放入hashmap中
                this.clientHashMap.put(socket, thread);
                thread.start();
            }
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }
}

class ClientThreads extends Thread{
    private Socket socket;
    private MasterSocketController masterSocketController;
    private FileController fileController;
    private String host_ip;
    private boolean isRunning = false;

    public BufferedReader input = null;
    public PrintWriter output = null;

    public ClientThreads(Socket socket, MasterSocketController masterSocketController)
            throws IOException {
        this.socket = socket;
        this.masterSocketController = masterSocketController;
        this.isRunning = true;
        this.fileController = new FileController();
        this.input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        this.output = new PrintWriter(socket.getOutputStream(), true);
        System.out.println("INFO: Successfully created new client thread from " + socket.getPort());
        host_ip = SocketUtils.getHostAddress();
    }

    @Override
    public void run() {
        System.out.println("INFO: Start listening to client from " + socket.getInetAddress() + ":" + socket.getPort());
        String line;
        try {
            while (isRunning) {
                Thread.sleep(Long.parseLong("1000"));
                line = input.readLine();
                if (line != null) {
                    String info = line.substring(2);
                    String result = this.commandProcess(info, socket.getInetAddress().toString());
                    if(!result.equals("Has no change")) {
                        masterSocketController.sendToMaster(result);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static BufferedReader StringToBufferedReader(String source){
        ByteArrayInputStream byteArrayInputStream = new ByteArrayInputStream(source.getBytes());
        InputStream inputStream = byteArrayInputStream;
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        return reader;
    }

    public void sendToClient(String info) {
        output.println("RI" + info);
    }

    // 从服务器处理接收到的命令，和出服务器的交互就在这一方法下面继续扩展

    public String commandProcess(String sql, String ip) throws Exception {
        System.out.println("INFO: Receive From client" + ip + "\n" + sql);
        sql = sql + "\n";
        InputStream is = new ByteArrayInputStream(sql.getBytes());
        BufferedReader buf = new BufferedReader(new InputStreamReader(is));
        String result = Interpreter.Parsing(buf);
        System.out.println("INFO: Processed result from miniSQL\n" + result);
        if (result==null){
            result="unexpected error! please try again";
        }
        API.store();
        sendToClient(result);
        String[] parts = sql.split(" ");
        String[] res = result.split(" ");
        String return_result;
        if(res[0].equals("create")) {
            sendToBackup(res[2]);
            sendCatalogToBackup();
            //System.out.println("R2" + res[2] + " add");
            return_result = "R2" + res[2] + " add";
        }
        else if(res[0].equals("drop")) {
            deleteFromBackup(res[2]);
            sendCatalogToBackup();
            //System.out.println("R2" + res[2] + " delete");
            return_result =  "R2" + res[2] + " delete";
        }
        else if(res[0].equals("insert") || res[0].equals("delete")) {
            //System.out.println(parts[2]);
            sendToBackup(parts[2]);
            sendCatalogToBackup();
            //System.out.println("success");
            return_result =  "Has no change";
        }
        else return_result =  "Has no change";
        System.out.println("INFO: Message will send to client\n" + return_result);
        return return_result;
    }

    public void sendToBackup(String fileName) {

        fileController.uploadFile(BackupInfo.DEFAULT_DIR + File.separatorChar + host_ip, fileName);
    }

    public void deleteFromBackup(String fileName) {
        fileController.deleteFile(BackupInfo.DEFAULT_DIR + File.separatorChar + host_ip, fileName);
    }

    public void sendCatalogToBackup() {
        fileController.uploadFile(BackupInfo.DEFAULT_DIR + File.separatorChar + host_ip,
                "table catalog");
        fileController.uploadFile(BackupInfo.DEFAULT_DIR + File.separatorChar + host_ip,
                "index catalog");
    }

}
