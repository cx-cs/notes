package com.tostring_equal;

public class test {
    public static void main(String[] args) {
        student s1=new student();
        System.out.println(s1);//看源码可找到object的tostring方法，默认返回包类名@地址，重写
        System.out.println(s1.toString());
        student s2=new student();
        System.out.println(s1==s2);//比地址
        System.out.println(s1.equals(s2));//object的equal比地址（String已经重写），重写为比内容
    }
}