package com.variableparameters;

public class test {
    public static void main(String[] args) {
        System.out.println(sum(1,2,3,4,5));
    }
    public static int sum(int a,int b,int... c){
        int sum=0;
        for(int i:c){
            sum+=i;
        }
        return sum+a+b;
    }
}
