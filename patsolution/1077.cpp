#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int n;
	scanf("%d\n",&n);//����������з���Ȼgetline 
    string ans;
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        int lens=s.length();
        reverse(s.begin(),s.end());
        if(i==0){
            ans=s;
            continue;
        }else{
            int lenans=ans.length();
            if(lens<lenans)swap(ans,s);
            int minlen=min(lens,lenans);
            for(int j=0;j<minlen;j++)
                if(ans[j]!=s[j]){//�ҵ�һ������ȵľͽ�ȡ�Ӵ�0��j-1 
                    ans=ans.substr(0,j);
                    break;
                }
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.length()==0)ans="nai";
    cout<<ans;
    return 0;
}
