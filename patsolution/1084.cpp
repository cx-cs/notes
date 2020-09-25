#include<iostream>
#include<cctype>
using namespace std;
int main(){//这道题不是找不同而是找没有的 
    string s1,s2,ans;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++)//找不到 
        if(s2.find(s1[i])==string::npos&&ans.find(toupper(s1[i]))==string::npos)
            ans+=toupper(s1[i]);
    cout<<ans;
    return 0;
}
