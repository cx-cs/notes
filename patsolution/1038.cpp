#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp0(string a, string b){
    return a+b<b+a;//只能这样排不能根据首字母因为长度可能不一样 
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
        s+=str[i];//加法 
    while(s.length()!=0&&s[0]=='0')
        s.erase(s.begin());//擦除0 
    if(s.length()==0)cout<<0;
    cout<<s;
    return 0;
}
