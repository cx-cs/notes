package com.tcp2;

import java.io.*;
import java.net.Socket;

public class ServerThread implements Runnable {
    private Socket s;
    public ServerThread(Socket s) {
        this.s=s;
    }

    @Override
    public void run() {
        try {
            BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
            int count=0;
            File file=new File("F:\\javatest\\server["+count+"].txt");
            if(file.exists()){
                count++;
                file=new File("F:\\javatest\\server["+count+"].txt");
            }
            BufferedWriter bw=new BufferedWriter(new FileWriter(file));
            String line;
            while((line=br.readLine())!=null){
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
            BufferedWriter bwfeedback=new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
            bwfeedback.write("文件上传成功");
            bwfeedback.newLine();
            bwfeedback.flush();
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
