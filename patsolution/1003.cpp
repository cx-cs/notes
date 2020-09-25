#include<iostream>
#include<algorithm>
using namespace std;
const int inf=99999999;
int main(){
	int city,road,src,dst;
	int team[500],e[500][500],d[500],visit[500]={0};//救援队数，边权，距离，访问标记 
	cin>>city>>road>>src>>dst;
	for(int i=0;i<city;i++)
		cin>>team[i];
	fill(e[0],e[0]+500*500,inf);
	for(int i=0;i<road;i++){
		int t1,t2,c;
		cin>>t1>>t2>>c;
		e[t1][t2]=e[t2][t1]=c;
	}
	fill(d,d+city,inf);//初始一个点都没有，距离无穷 
	int numroads[500],maxteams[500];//到i城最短路径数，到i城最大队数 
	numroads[src]=1;
	maxteams[src]=team[src];
	d[src]=0;
	while(1){
		int dmin=inf,dmini=-1;
		for(int i=0;i<city;i++)
			if(!visit[i]&&d[i]<dmin){
				dmin=d[i];
				dmini=i;
			}
			if(dmini==-1)break;
			visit[dmini]=1;
			for(int i=0;i<city;i++){
				if(e[dmini][i]!=inf&&!visit[i]){
					if(d[i]>d[dmini]+e[dmini][i]){
						numroads[i]=numroads[dmini];//重置路径数
						maxteams[i]=maxteams[dmini]+team[i];//重置点权
						d[i]=d[dmini]+e[dmini][i];//更新距离
					}
					else if(d[i]==d[dmini]+e[dmini][i]){//相等说明有多条路 
						numroads[i]=numroads[i]+numroads[dmini];//更新路径数
						maxteams[i]=max(maxteams[i],maxteams[dmini]+team[i]);//更新点权
					}
				}
			}
	}
	cout<<numroads[dst]<<" "<<maxteams[dst];
	system("pause");
}
