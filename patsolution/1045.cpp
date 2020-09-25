//最长非降子序列长度
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,L,ans=1;
	cin>>n>>m;
	vector<int> hash(n+1),v,dp(n+1);//dp[i]表示以i结尾的最长非降子序列长度
	for(int i=1;i<=m;i++){
		int color;
		cin>>color;
		hash[color]=i;
	}
	cin>>L;
	for(int i=0;i<L;i++){
		int color;
		cin>>color;
		if(hash[color]!=0)
			v.push_back(hash[color]);
	}
	for(int i=0;i<v.size();i++){
		int maxx=-1;
		for(int j=1;j<=v[i];j++)
			maxx=max(maxx,dp[j]);//找出以v[i]结尾的最长非降子序列长度
		dp[v[i]]=maxx+1;
		ans=max(dp[v[i]],ans);
	}
	cout<<ans;
	system("pause");
}