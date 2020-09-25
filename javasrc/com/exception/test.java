package com.exception;
import java.text.ParseException;
import java.util.Date;
import java.text.SimpleDateFormat;

public class test {
    public static void main(String[] args) throws ParseException {
        System.out.println("begin");
        method();
        System.out.println("end");
        method2();
        System.out.println("end2");
    }
    public static void method(){//运行异常
        try {//可以使程序执行结束
            int[] a = {1, 2, 3};
            System.out.println(a[3]);
        } catch(ArrayIndexOutOfBoundsException e){
            //throwable三个方法，一般用第三个
            //System.out.println(e.getMessage());
            //System.out.println(e.toString());
            e.printStackTrace();//输出异常信息
        }
    }
    public static void method2() throws ParseException {//编译异常
        //throws只是抛出不处理，程序不能结束
        String s="2010-01-01";
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd");
        Date d=sdf.parse(s);
        System.out.println(d);
    }
}
