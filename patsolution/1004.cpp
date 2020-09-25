#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100];//╨╒всаз╫с╠М
int leaf[100];
int maxdepth=1;
void dfs(int id,int depth){
	if(v[id].size()==0){
		leaf[depth]++;
		maxdepth=max(maxdepth,depth);
		return;
	}
	for(int i=0;i<v[id].size();i++)
		dfs(v[id][i],depth+1);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int id,num;
		cin>>id>>num;
		for(int j=0;j<num;j++){
			int idc;
			cin>>idc;
			v[id].push_back(idc);
		}
	}
	dfs(1,1);
	for(int i=1;i<=maxdepth;i++)
		cout<<(i==1?"":" ")<<leaf[i];
	system("pause");
}
