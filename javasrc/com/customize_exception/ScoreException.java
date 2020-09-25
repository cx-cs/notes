package com.customize_exception;
//自定义异常
public class ScoreException extends Exception{
    public ScoreException(){};
    public ScoreException(String message){
        super(message);
    }
}
