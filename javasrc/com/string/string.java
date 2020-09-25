package com.string;
public class string {
    public static void main(String[] args) {
        String s1 = "abc";
        String s2=new String("abc");
        System.out.println(s1 == s2);//比较地址
        System.out.println(s1.equals(s2));//比较内容
        //string和stringbuilder转化
        StringBuilder st = new StringBuilder(s1);
        System.out.println(st);
        String s3 = st.toString();
        System.out.println(s3);
    }
}
