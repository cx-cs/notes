#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> weight(n),rank(n);
	for(int i=0;i<n;i++)
		cin>>weight[i];
	queue<int> q;
	for(int i=0;i<n;i++){
		int index;
		cin>>index;
		q.push(index);
	}
	while(!q.empty()){
		if(q.size()==1){
			rank[q.front()]=1;
			break;
		}
		int group=q.size()%m==0?q.size()/m:q.size()/m+1;
		int index=0,lastsize=q.size();
		for(int i=0;i<group;i++){
			int maxmouse=q.front();
			for(int j=0;j<m&&index<lastsize;index++,j++){
				rank[q.front()]=group+1;
				if(weight[maxmouse]<weight[q.front()])
					maxmouse=q.front();
				q.pop();
			}
			q.push(maxmouse);
		}
	}
	for(int i=0;i<n;i++)
		cout<<(i==0?"":" ")<<rank[i];
	system("pause");
	return 0;
}