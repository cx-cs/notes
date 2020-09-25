package com.genericclass;

public class test {
    public static void main(String[] args) {
        generic<String> g=new generic<>();
        g.setT("ssss");
        System.out.println(g.getT());

        generic<Boolean> b=new generic<>();
        b.setT(true);
        System.out.println(b.getT());

        genericm gm=new genericm();
        gm.show("hello");
        gm.show(true);
    }
}
