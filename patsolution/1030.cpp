#include<iostream>
#include<vector>
using namespace std;
const int inf=99999999;
int n,m,src,dst;
int w[500][500],cost[500][500],d[500],visit[500],pre[500],co[500];
void dfs(int v){
	if(v==src){
		cout<<v<<" ";
		return;
	}
	dfs(pre[v]);
	cout<<v<<" ";
}
int main(){
	fill(w[0],w[0]+500*500,inf);
	cin>>n>>m>>src>>dst;
	for(int i=0;i<m;i++){
		int c1,c2,d,c;
		cin>>c1>>c2>>d>>c;
		w[c1][c2]=w[c2][c1]=d;
		cost[c1][c2]=cost[c2][c1]=c;
	}
	fill(d,d+500,inf);
	fill(co,co+500,inf);
	fill(visit,visit+500,0);
	d[src]=0;
	co[src]=0;
	while(1){
		int index=-1,min=inf;
		for(int i=0;i<n;i++)
			if(!visit[i]&&d[i]<min){
				min=d[i];
				index=i;
			}
		if(index==-1)break;
		visit[index]=1;
		for(int i=0;i<n;i++)
			if(w[index][i]!=inf&&!visit[i]){
				if(w[index][i]+d[index]<d[i]){
					d[i]=w[index][i]+d[index];
					pre[i]=index;
					co[i]=co[index]+cost[index][i];
				}
				else if(w[index][i]+d[index]==d[i]&&co[i]>co[index]+cost[index][i]){
					pre[i]=index;
					co[i]=co[index]+cost[index][i];
				}
			}
	}
	dfs(dst);
	cout<<d[dst]<<" "<<co[dst];
	system("pause");
}