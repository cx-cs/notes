//dp[i][j]Ϊ���ĵȼ���dp[i+1][j-1]Ϊ������s[i]=s[j]
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin,s);
	int len=s.length(),maxx=1;
	vector<vector<int>> dp(len, vector<int>(len, 0));
	for(int i=0;i<len;i++)//��ʼ������
		dp[i][i]=1;
	for(int i=0;i<len-1;i++){//��ʼ������
		if(s[i]==s[i+1]){
			dp[i][i+1]=1;
			maxx=2;
		}
	}
	for(int cnt=2;cnt<=len-1;cnt++){//���
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