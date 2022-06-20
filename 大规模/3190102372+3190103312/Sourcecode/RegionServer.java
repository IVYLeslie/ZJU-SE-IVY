import RegionController.RegionController;

import java.io.File;

//在主节点注册的时候，data 为 该从节点在集群局域网的ip地址

public class RegionServer {
    public static void main(String[] args) throws Exception {
        File data_directory = new File("db");
        if(!data_directory.exists()) {
            data_directory.mkdir();
        }
        RegionController regionController = new RegionController();
        regionController.run();
    }
}
