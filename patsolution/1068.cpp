#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> coin(n+1);
	vector<vector<int> > dp(n+1,vector<int>(m+1));
	vector<vector<int> > select(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)
		cin>>coin[i];
	sort(coin.begin()+1,coin.end(),greater<int>());//这里降序是因为输出时从小输出所以要先凑大的再凑小的这样才能用m反过来输出
	//背包问题是d[i][容量]=价值,这题是d[i][币值]=[币值]
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(coin[i]>j)//第i个币值太大放不进去
				dp[i][j]=dp[i-1][j];
			else{//能放进去
				dp[i][j]=max(dp[i-1][j],coin[i]+dp[i-1][j-coin[i]]);//放和不放选大的
				if(coin[i]+dp[i-1][j-coin[i]]>=dp[i-1][j])//看看有没有放进去，这里必须等因为小序列优先
					select[i][j]=1;
			}
		}
	}
	if(dp[n][m]!=m){
		cout<<"No Solution";
	} 
	else{
		bool output=false;
		for(int i=n,j=m;i>=1&&j>=1;i--){
			if(select[i][j]){
				cout<<(output?" ":"")<<coin[i];
				output=true;
				j-=coin[i];
			}
		}
	}
	system("pause");
}