#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int weight;
	vector<int> next;
}nod[101];
bool cmp(int a,int b){
	return nod[a].weight>nod[b].weight;
}
vector<int> tmp;
int num;
void dfs(int node,int sum){
	tmp.push_back(node);
	sum+=nod[node].weight;
	if(sum==num&&nod[node].next.size()==0){
		printf("%d",nod[0].weight);
		for(int i=1;i<tmp.size();i++)
			printf(" %d",nod[tmp[i]].weight);
		printf("\n");
		tmp.pop_back();
		return;
	}
	for(int i=0;i<nod[node].next.size();i++)
		dfs(nod[node].next[i],sum);
	tmp.pop_back();
}
int main(){
	int n,m;
	scanf("%d %d %d",&n,&m,&num);
	for(int i=0;i<n;i++)
		scanf("%d",&nod[i].weight);
	for(int i=0;i<m;i++){
		int now,nowm;
		scanf("%d %d",&now,&nowm);
		nod[now].next.resize(nowm);
		for(int j=0;j<nowm;j++)
			scanf("%d",&nod[now].next[j]);
		sort(nod[now].next.begin(),nod[now].next.end(),cmp);//只要排一次序，路径就已经按大小排好了 
	}
	dfs(0,0);
}
