#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct student{
	int id,best,score[4],rank[4];
};
vector<student> v;
map<int,int> idmap;
int subject;
int cmp(student a,student b){
	return a.score[subject]>b.score[subject];
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		student stu;
		cin>>stu.id>>stu.score[1]>>stu.score[2]>>stu.score[3];
		stu.score[0]=(stu.score[1]+stu.score[2]+stu.score[3])/3.0;
		v.push_back(stu);
	}
	for(subject=0;subject<4;subject++){
		sort(v.begin(),v.end(),cmp);
		v[0].rank[subject]=1;
		for(int i=1;i<n;i++){
			if(v[i].score[subject]==v[i-1].score[subject])
				v[i].rank[subject]=v[i-1].rank[subject];
			else v[i].rank[subject]=i+1;//同分数注意排名后移 
		}
	}
	for(int i=0;i<n;i++){
		idmap[v[i].id]=i;//排完序后再映射不然对应不上
		int bestt=0,minn=v[i].rank[0];
		for(int j=1;j<4;j++)
			if(v[i].rank[j]<minn){
				minn=v[i].rank[j];
				bestt=j;
			}
		v[i].best=bestt;
	}
	string s="ACME";
	for(int i=0;i<m;i++){
		int sid;
		cin>>sid;
		if(idmap.count(sid)){
			int index=idmap[sid];
			int bestt=v[index].best;
			cout<<v[index].rank[bestt]<<" "<<s[bestt]<<endl;
		}
		else cout<<"N/A"<<endl;
	}
	system("pause");
}
