package com.tostring_equal;

public class student {
    int age=10;

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override//重写了object根类的，equals也可以重写判断类内容而非地址
    public String toString() {
        return "student{" +
                "age=" + age +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        student student = (student) o;
        return age == student.age;
    }
}
