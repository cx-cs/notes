#include<iostream>
#include<cstdio>
using namespace std;
int connect[1000][1000]={0};
int visit[1000];
void dfs(int j){
	visit[j]=1;
	for(int i=0;i<1000;i++)
		if(connect[j][i]!=0&&visit[i]!=1){
			dfs(i);
		}
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		c1--;c2--;
		connect[c2][c1]=connect[c1][c2]=1;
	}
	for(int i=0;i<k;i++){
		int city;
		cin>>city;
		city--;
		fill(visit,visit+1000,0);
		int cnt=0;
		visit[city]=1;
		for(int j=0;j<n;j++){
			if(visit[j]==0){
				dfs(j);
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
}
