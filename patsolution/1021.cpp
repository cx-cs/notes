#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<vector<int> >v;
vector<int> tmp;//用来存最深根结点
int maxheight=0; 
bool visit[10001]={0};
void dfs(int node,int height){
	visit[node]=1;
	if(height>maxheight){
		maxheight=height;
		tmp.clear();
		tmp.push_back(node);
	}
	else if(height==maxheight)tmp.push_back(node);
	for(int i=0;i<v[node].size();i++)
		if(!visit[v[node][i]])dfs(v[node][i],height+1);
}
int main(){
	int n;
	cin>>n;
	v.resize(n+1);
	for(int i=1;i<=n-1;i++){//只有n-1条边 
		int c1,c2;
		cin>>c1>>c2;
		v[c1].push_back(c2);//直接存边 
		v[c2].push_back(c1);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!visit[i]){
			dfs(i,1);
			cnt++;
		}
	set<int> s;
	if(cnt>1)cout<<"Error: "<<cnt<<" components";
	else{
		for(int i=0;i<tmp.size();i++)
			s.insert(tmp[i]);
		fill(visit,visit+10001,0);
		maxheight=0;
		int s1=tmp[0];
		tmp.clear(); 
		dfs(s1,1);//第一次搜索可能不是最大高度但是结点是最深根，再以其中一个开始深搜即可找完所有最深根 
		for(int i=0;i<tmp.size();i++)
			s.insert(tmp[i]);
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++)//集合会自动排序 
		cout<<*it<<endl;
}
