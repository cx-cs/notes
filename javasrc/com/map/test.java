package com.map;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class test {
    public static void main(String[] args) {
        Map<String,String> m=new HashMap<>();
        m.put("1","a");
        m.put("2","b");

        Set<String> key=m.keySet();//所有健的集合
        for(String i:key){
            System.out.println(m.get(i));
        }

        Collection<String> values=m.values();//所有值的集合
        for(String i:values){
            System.out.println(i);
        }

        //遍历方式二
        Set<Map.Entry<String,String>> kv=m.entrySet();
        for(Map.Entry<String,String> i:kv){
            System.out.println(i.getKey()+','+i.getValue());
        }
    }
}
