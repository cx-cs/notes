//0 1的情况不会考虑前面的0
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxx,start,end;
	cin>>n;
	vector<int> v(n),dp(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		dp[i]=v[i];
	}
	maxx=v[0];
	start=end=0;
	for(int i=1;i<n;i++){
		dp[i]=max(dp[i],dp[i-1]+dp[i]);//以i结尾的最大子序列
		if(maxx<dp[i]){
			end=i;
			maxx=dp[i];
		}
	}
	int sum=0;
	for(int i=end;i>=0;i--){
		sum+=v[i];
		if(sum==maxx){
			start=i;
			break;
		}
	}
	if(maxx<0)cout<<0<<" "<<v[0]<<" "<<v[n-1];
	else cout<<maxx<<" "<<v[start]<<" "<<v[end];
	system("pause");
}
/*#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,maxx,start,end;
	cin>>n;
	vector<int> v(n),dp(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		dp[i]=v[i];
	}
	maxx=v[0];
	start=end=0;
	for(int i=n-1;i>=1;i--){
		dp[i-1]=max(dp[i-1],dp[i-1]+dp[i]);//以i开头的最大子序列
		if(dp[i-1]>=maxx){
			maxx=dp[i-1];
			start=i-1;
		}
	}
	int sum=0;
	for(int i=start;i<n;i++){
		sum+=v[i];
		if(sum==maxx){
			end=i;
			break;
		}
	}
	if(maxx<0)cout<<0<<" "<<v[0]<<" "<<v[n-1];
	else cout<<maxx<<" "<<v[start]<<" "<<v[end];
	system("pause");
}*/