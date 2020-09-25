#include<iostream>
#include<map>
using namespace std;
int main(){
    int m,n,s;
    cin>>m>>n>>s;
    string str;
    map<string,int> mapp;
    bool flag=false;
    for(int i=1;i<=m;i++){
        cin>>str;
        if(mapp.count(str)==1)s=s+1;//已经获奖了 
        if(i==s&&mapp.count(str)==0){//初始值为0 
            mapp[str]=1;//获奖 
            cout<<str<<endl;
            flag=true;
            s=s+n;
        }
    }
    if(mapp.size()==0)cout<<"Keep going...";
    return 0;
}
