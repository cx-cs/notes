package com.fileinputstream1;

import java.io.FileInputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        FileInputStream fis=new FileInputStream("F:\\javatest\\input.txt");
        int by;//一次读出一字节
        while((by=fis.read())!=-1){
            System.out.print((char)by);
        }
        fis.close();
    }
}
