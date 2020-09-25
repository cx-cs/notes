package com.producer_consumer;

public class box {
    private int milk;
    int milknum=0;
    public synchronized void put(int milk){
        if(milknum>0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.milk=milk;
        System.out.println("把第"+this.milk+"瓶奶放入");
        milknum++;
        notifyAll();
    }
    public synchronized void get(){
        if(milknum==0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("取出第"+this.milk+"瓶奶");
        milknum--;
        notifyAll();
    }
}
