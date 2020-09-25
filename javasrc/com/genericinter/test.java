package com.genericinter;

import java.util.ArrayList;
import java.util.List;

public class test {
    public static void main(String[] args) {
        generic<String> g=new genericImpl<>();
        g.show("dd");
        generic<Integer> i=new genericImpl<>();
        i.show(11);
        //类型通配符
        List<?> l1=new ArrayList<Object>();
        List<? extends Number> l3=new ArrayList<Integer>();//<=number子类
        List<? super Number> l4=new ArrayList<Object>();//>=number
    }
}
