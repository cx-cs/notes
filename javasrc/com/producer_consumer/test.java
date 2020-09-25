package com.producer_consumer;

public class test {
    public static void main(String[] args) {
        box b=new box();
        producer p=new producer(b);
        consumer c=new consumer(b);
        Thread t1=new Thread(p);
        Thread t2=new Thread(c);
        t1.start();
        t2.start();
    }
}
