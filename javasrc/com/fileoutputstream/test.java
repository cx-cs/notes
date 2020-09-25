package com.fileoutputstream;

import java.io.FileOutputStream;
import java.io.IOException;

public class test {
    public static void main(String[] args) throws IOException {
        FileOutputStream fo=new FileOutputStream("F:\\javatest\\output.txt");
        fo.write(97);
        fo.write(57);//写一个字节
        byte[] bys={97,98,99};
        byte[] bys2="gghh".getBytes();
        fo.write(bys);//写一个字节数组
        fo.write(bys2,1,2);//从off写len长
        fo.close();
        FileOutputStream fos=new FileOutputStream("F:\\javatest\\output.txt",true);
        fos.write("追".getBytes());
        fos.write("\r\n加".getBytes());
        fos.close();
    }
}