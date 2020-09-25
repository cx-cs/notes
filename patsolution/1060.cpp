#include<iostream>
#include<string>
using namespace std;
int f(const string&s,string&temp,int N){
    int point=s.size(),index=-1;//point小数点的位置，初始化为最后一位，index指示s中第一位非零数字的位置，初始化为-1
    for(int i=0;i<s.size();i++)
        if(s[i]=='.')//找出小数点位置
            point=i;
        else if(index!=-1&&temp.size()<N)//有效数字 
            temp+=s[i];
        else if(index==-1&&s[i]!='0'){//找到字符串s第一位非零数字的位置
            index=i;
            temp+=s[i];
        }
    while(temp.size()<N)
        temp+="0";//在字符串末尾加足够的0保证有N位有效数字
    if(index==-1)//没有找到非零数字，说明字符串s表示的数是0
        return 0;
    point-=index;//小数点位置减去第一位非零数字位置得到指数
    return point<0?point+1:point;//当前point为负数，返回point+1；否则返回point
}
int main(){
    int N;
    string A,B,Atemp="",Btemp="";
    cin>>N>>A>>B;//读取数据
    int Aexp=f(A,Atemp,N),Bexp=f(B,Btemp,N);
    if(Aexp==Bexp&&Atemp==Btemp)//有效数字和指数均相等
        cout<<"YES 0."<<Atemp<<"*10^"<<Aexp;
    else
        cout<<"NO 0."<<Atemp<<"*10^"<<Aexp<<" 0."<<Btemp<<"*10^"<<Bexp;
    return 0;
}
