package com.bufferedio;

import java.io.*;

//字节流缓存
public class test {
    public static void main(String[] args) throws IOException {
        BufferedOutputStream bos=new BufferedOutputStream(new FileOutputStream("F:\\javatest\\output.txt"));
        //bos.write("hello".getBytes());
        bos.close();

        BufferedInputStream bis=new BufferedInputStream(new FileInputStream("F:\\javatest\\input.txt"));
        //bis读跟之前一样字节或字节数组
        bis.close();
    }
}
