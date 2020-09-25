package com.fileinputstream2;

import java.io.FileInputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        FileInputStream fis=new FileInputStream("F:\\javatest\\input.txt");
        byte[] bys=new byte[1024];
        int len;
        while((len=fis.read(bys))!=-1){
            System.out.print(new String(bys,0,len));
        }
        fis.close();
    }
}
