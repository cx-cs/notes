#include<iostream>
#include<map>
#include<cctype>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    map<string,int> m;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){//是字母数字 
            s[i]=tolower(s[i]);//转换小写，数字也可以 
            t+=s[i];//字符串加 
        }
        if(!isalnum(s[i])||i==s.length()-1){//单词读完了或到结尾 
            if(t.length()!=0)m[t]++;//映射 
            t="";//t重置 
        }
    }
    int maxn=0;
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
        if(it->second>maxn){
            t=it->first;
            maxn=it->second;
        }
    cout<<t<<" "<<maxn;
    return 0;
}
