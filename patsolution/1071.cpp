#include<iostream>
#include<map>
#include<cctype>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    map<string,int> m;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){//����ĸ���� 
            s[i]=tolower(s[i]);//ת��Сд������Ҳ���� 
            t+=s[i];//�ַ����� 
        }
        if(!isalnum(s[i])||i==s.length()-1){//���ʶ����˻򵽽�β 
            if(t.length()!=0)m[t]++;//ӳ�� 
            t="";//t���� 
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
