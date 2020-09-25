package com.AnonymousInnerClass;

public class test {
    public static void main(String[] args) {
        jumping_operator jo=new jumping_operator();
        jumping j=new cat();
        jo.use(j);

        //匿名内部类，即接口的匿名对象实例
        jo.use(new jumping() {
            @Override
            public void jump() {
                System.out.println("猫跳高了");
            }
        });

        new jumping() {
            @Override
            public void jump() {
                System.out.println("猫跳高了");
            }
        }.jump();

        jumping k=new jumping() {
            @Override
            public void jump() {
                System.out.println("猫跳高了");
            }
        };
        k.jump();
    }
}