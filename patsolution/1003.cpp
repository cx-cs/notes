#include<iostream>
#include<algorithm>
using namespace std;
const int inf=99999999;
int main(){
	int city,road,src,dst;
	int team[500],e[500][500],d[500],visit[500]={0};//��Ԯ��������Ȩ�����룬���ʱ�� 
	cin>>city>>road>>src>>dst;
	for(int i=0;i<city;i++)
		cin>>team[i];
	fill(e[0],e[0]+500*500,inf);
	for(int i=0;i<road;i++){
		int t1,t2,c;
		cin>>t1>>t2>>c;
		e[t1][t2]=e[t2][t1]=c;
	}
	fill(d,d+city,inf);//��ʼһ���㶼û�У��������� 
	int numroads[500],maxteams[500];//��i�����·��������i�������� 
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
						numroads[i]=numroads[dmini];//����·����
						maxteams[i]=maxteams[dmini]+team[i];//���õ�Ȩ
						d[i]=d[dmini]+e[dmini][i];//���¾���
					}
					else if(d[i]==d[dmini]+e[dmini][i]){//���˵���ж���· 
						numroads[i]=numroads[i]+numroads[dmini];//����·����
						maxteams[i]=max(maxteams[i],maxteams[dmini]+team[i]);//���µ�Ȩ
					}
				}
			}
	}
	cout<<numroads[dst]<<" "<<maxteams[dst];
	system("pause");
}
