package com.tcp2;

import java.io.*;
import java.net.Socket;

public class client {
    public static void main(String[] args) throws IOException {
        Socket s=new Socket("172.27.74.121",12345);
        BufferedReader br=new BufferedReader(new FileReader("F:\\javatest\\client.txt"));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
        String line;
        while((line=br.readLine())!=null){
            bw.write(line);
            bw.newLine();
            bw.flush();
        }
        s.shutdownOutput();//关输出

        BufferedReader brfeedback=new BufferedReader(new InputStreamReader(s.getInputStream()));
        String feedback=brfeedback.readLine();
        System.out.println("服务器反馈:"+feedback);

        br.close();
        s.close();
    }
}
