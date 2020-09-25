package com.customize_exception;

public class teacher {
    public void checkscore(int score) throws ScoreException{
        if(score>100)
            throw new ScoreException("分数异常");
        else System.out.println("正常");
    }
}
