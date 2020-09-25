#include<iostream>
#include<vector>
using namespace std;
const int inf=99999999;
int minneed=inf,minback=inf;
vector<int> tmp,path,pre[501];
int num[501];
void dfs(int sp){
	tmp.push_back(sp);
	if(sp==0){
		int need=0,back=0;
		for(int i=tmp.size()-1;i>=0;i--){
			int index=tmp[i];
			if(num[index]>0)back+=num[index];
			else{
				if(back+num[index]>=0)back+=num[index];
				else{
					need-=num[index]+back; 
					back=0;
				}
			}
		}
		if(minneed>need){
			minneed=need;
			minback=back;
			path=tmp;
		}
		else if(minneed==need&&minback>back){
			minback=back;
			path=tmp;
		}
		tmp.pop_back();
		return;
	}
	for(int i=0;i<pre[sp].size();i++)dfs(pre[sp][i]);
	tmp.pop_back();
}
int main(){
	int cmax,n,sp,m;
	int w[501][501],d[501],visit[501]={0};
	cin>>cmax>>n>>sp>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		num[i]=num[i]-cmax/2;
	}
	fill(w[0],w[0]+501*501,inf);
	for(int i=0;i<m;i++){
		int s1,s2,w1;
		cin>>s1>>s2>>w1;
		w[s1][s2]=w[s2][s1]=w1;
	}
	fill(d,d+501,inf);
	d[0]=0;
	while(1){
		int min=inf,index=-1;
		for(int i=0;i<=n;i++)
			if(d[i]<min&&!visit[i]){
				min=d[i];
				index=i;
			}
			if(index==-1)break;
			visit[index]=1;
			for(int i=0;i<=n;i++)
				if(!visit[i]&&w[index][i]!=inf){
					if(d[i]>w[index][i]+d[index]){
						d[i]=w[index][i]+d[index];
						pre[i].clear();
						pre[i].push_back(index);
					}
					else if(d[i]==w[index][i]+d[index])pre[i].push_back(index);
				}
	}
	dfs(sp);
	cout<<minneed<<" 0";
	for(int i=path.size()-2;i>=0;i--)
		cout<<"->"<<path[i];
	cout<<" "<<minback;
}