#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
	int len1,len2,cnt=0;
	cin>>len1;
	vector<long int> v(len1+2);
	for(int i=1;i<=len1;i++)
		scanf("%ld",&v[i]);
	v[len1+1]=0x7fffffff;//这是INT_MAX 
	cin>>len2;
	int mid=(len1+len2+1)/2,i=1;//从1开始 
	long int tmp;
	for(int j=1;j<=len2;j++){
        cin>>tmp;
        while(v[i]<tmp){
            cnt++;
            if(cnt==mid)cout<<v[i];//在第一个数组就碰到 
            i++;
        }
        cnt++;//这里遍历到tmp 
        if(cnt==mid)cout<<tmp;
    }
    while(i<=len1){//还在第一个数组 
        cnt++;
        if(cnt==mid)cout<<v[i];
        i++;
    }
}
