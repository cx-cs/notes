package com.producer_consumer;

public class producer implements Runnable{
    private box b;
    producer(box b){
        this.b=b;
    }
    public void run(){
        for(int i=1;i<=15;i++)
            b.put(i);
    }
}
