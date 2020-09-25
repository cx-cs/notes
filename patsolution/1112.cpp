#include<iostream>
using namespace std;
int main(){
    string input,output="";
    int K;
    cin>>K>>input;
    int hashTable[128]={0};//表示是不是坏键
    for(int i=0;i<input.size();){
        int j=i+1;
        while(j<input.size()&&input[j]==input[i])//找到i位置后第一个不等于input[i]的字符位置
            ++j;
        if(hashTable[input[i]]>=0)//当前的input[i]可能是坏键或者没出现过 
            hashTable[input[i]]=(j-i)%K==0?1:-1;
        i=j;
    }
    bool out[128]={false};//表示字符是否已被输出过
    for(int i=0;i<input.size();){
        output+=input[i];//将当前字符加入正确的字符串中
        if(hashTable[input[i]]>0){//是坏键
            if(!out[input[i]]){
                cout<<input[i];
                out[input[i]]=true;//此坏键已被输出过
            }
            i+=K;//每K个坏键在正确的字符串中只输出1次
        }
        else if(hashTable[input[i]]<0)//不是坏键
            i++;
    }
    cout<<endl<<output;//输出正确的字符串
    return 0;
}
