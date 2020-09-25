#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int id,score;
	char name[10];
};
bool cmp1(node a,node b){
	return a.id<b.id;
}
bool cmp2(node a,node b){
	return (strcmp(a.name,b.name)!=0)?(strcmp(a.name,b.name)<0):a.id<b.id;
}
bool cmp3(node a,node b){
	return a.score!=b.score?a.score<b.score:a.id<b.id;
}
int main(){
	int n,c;
	scanf("%d %d",&n,&c);
	vector<node> v;
	v.resize(n);//必须要否则不能cin 
	for(int i=0;i<n;i++)
		scanf("%d %s %d",&v[i].id,v[i].name,&v[i].score);
	if(c==1)sort(v.begin(),v.end(),cmp1);
	else if(c==2)sort(v.begin(),v.end(),cmp2);
	else sort(v.begin(),v.end(),cmp3);
	for(int i=0;i<v.size();i++)
		printf("%06d %s %d\n",v[i].id,v[i].name,v[i].score);
}
