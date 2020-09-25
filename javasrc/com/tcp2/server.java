package com.tcp2;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
    public static void main(String[] args) throws IOException {
        //每个客户端一个线程
        ServerSocket ss=new ServerSocket(12345);
        while(true){
            Socket s=ss.accept();
            new Thread(new ServerThread(s)).start();
        }
    }
}
