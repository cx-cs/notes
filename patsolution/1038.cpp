#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp0(string a, string b){
    return a+b<b+a;//ֻ�������Ų��ܸ�������ĸ��Ϊ���ȿ��ܲ�һ�� 
}
string str[10010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str[i];
    sort(str,str+n,cmp0);
    string s;
    for(int i=0;i<n;i++)
        s+=str[i];//�ӷ� 
    while(s.length()!=0&&s[0]=='0')
        s.erase(s.begin());//����0 
    if(s.length()==0)cout<<0;
    cout<<s;
    return 0;
}
