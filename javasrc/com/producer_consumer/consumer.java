package com.producer_consumer;

public class consumer implements Runnable{
    private box b;
    consumer(box b){
        this.b=b;
    }
    public void run(){
        while(true)
            b.get();
    }
}
