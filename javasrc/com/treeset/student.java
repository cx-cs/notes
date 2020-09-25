package com.treeset;

public class student implements Comparable<student>{
    int age;
    String name;
    public student (int age,String name){
        this.age=age;
        this.name=name;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }

    @Override
    public int compareTo(student s){
        return this.age!=s.age?this.age-s.age:this.name.compareTo(s.name);
    }
}
