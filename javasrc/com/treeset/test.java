package com.treeset;

import java.util.Comparator;
import java.util.TreeSet;

public class test {
    public static void main(String[] args) {
        TreeSet<student> s=new TreeSet<>();//无参构造要求实现接口重写compareto
        student s1=new student(20,"af");
        student s2=new student(19,"bc");
        student s3=new student(19,"bc");
        student s4=new student(19,"bd");
        student s5=new student(18,"bc");
        s.add(s1);
        s.add(s2);
        s.add(s3);
        s.add(s4);
        s.add(s5);
        for(student i:s){
            System.out.println(i.getName()+','+i.getAge());
        }

        //带参构造
        TreeSet<student> s6=new TreeSet<>(new Comparator<student>() {
            @Override
            public int compare(student o1, student o2) {//o1相当于this，>0则o1在后，相等不插入
                return o1.age!=o2.age?o1.age-o2.age:o1.name.compareTo(o2.name);
            }
        });
        s6.add(s1);
        s6.add(s2);
        s6.add(s3);
        s6.add(s4);
        s6.add(s5);
        for(student i:s6){
            System.out.println(i.getName()+','+i.getAge());
        }
    }
}
