//��ǽ������г���
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,L,ans=1;
	cin>>n>>m;
	vector<int> hash(n+1),v,dp(n+1);//dp[i]��ʾ��i��β����ǽ������г���
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
			maxx=max(maxx,dp[j]);//�ҳ���v[i]��β����ǽ������г���
		dp[v[i]]=maxx+1;
		ans=max(dp[v[i]],ans);
	}
	cout<<ans;
	system("pause");
}