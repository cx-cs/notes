package com.udp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class send {
    public static void main(String[] args) throws IOException {
        DatagramSocket ds=new DatagramSocket();
        //把键盘输入封装为字符缓冲流
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String line;
        while((line=br.readLine())!=null){
            if("886".equals(line))
                break;
            byte[] bys=line.getBytes();
            DatagramPacket dp=new DatagramPacket(bys,bys.length, InetAddress.getByName("172.27.74.121"),12345);
            ds.send(dp);
        }
        ds.close();
    }
}
