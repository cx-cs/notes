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
	sort(coin.begin()+1,coin.end(),greater<int>());//���ｵ������Ϊ���ʱ��С�������Ҫ�ȴմ���ٴ�С������������m���������
	//����������d[i][����]=��ֵ,������d[i][��ֵ]=[��ֵ]
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(coin[i]>j)//��i����ֵ̫��Ų���ȥ
				dp[i][j]=dp[i-1][j];
			else{//�ܷŽ�ȥ
				dp[i][j]=max(dp[i-1][j],coin[i]+dp[i-1][j-coin[i]]);//�źͲ���ѡ���
				if(coin[i]+dp[i-1][j-coin[i]]>=dp[i-1][j])//������û�зŽ�ȥ������������ΪС��������
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