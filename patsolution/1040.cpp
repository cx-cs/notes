//dp[i][j]为回文等价于dp[i+1][j-1]为回文且s[i]=s[j]
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int len=s.length(),maxx=1;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	for(int i=0;i<len;i++)//初始化单个
		dp[i][i]=1;
	for(int i=0;i<len-1;i++){//初始化两个
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			maxx=2;
		}
	}
	for(int cnt=2;cnt<=len-1;cnt++){//多个
		for(int i=0,j=i+cnt;j<len;i++,j++){
			if(dp[i+1][j-1]&&s[i]==s[j]){
				dp[i][j]=1;
				maxx=max(maxx,cnt+1);
			}
		}
	}
	cout<<maxx;
	system("pause");
}