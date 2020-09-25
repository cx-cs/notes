package com.genericclass;

public class generic<T> {//泛型类，类似c++模板
    T t;

    public T getT() {
        return t;
    }

    public void setT(T t) {
        this.t = t;
    }
}
