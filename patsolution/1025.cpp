#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	long long name;
	int score,lnum,frank,lrank;
};
vector<node> fin;
bool cmp(node a,node b){
	return a.score!=b.score?a.score>b.score:a.name<b.name;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		vector<node> v(m);
		for(int j=0;j<m;j++){
			cin>>v[j].name>>v[j].score;
			v[j].lnum=i;
		}
		sort(v.begin(),v.end(),cmp);
		int lrank=2;
		v[0].lrank=1;
		fin.push_back(v[0]);
		for(int j=1;j<m;j++){
			if(v[j].score==v[j-1].score)v[j].lrank=v[j-1].lrank;
			else v[j].lrank=lrank;
			lrank++;
			fin.push_back(v[j]);
		}
	}
	sort(fin.begin(),fin.end(),cmp);
	int frank=2;
	fin[0].frank=1;
	for(int j=1;j<fin.size();j++){
		if(fin[j].score==fin[j-1].score)fin[j].frank=fin[j-1].frank;
		else fin[j].frank=frank;
		frank++;
	}
	cout<<fin.size()<<endl;
	for(int i=0;i<fin.size();i++)
		printf("%013lld %d %d %d\n",fin[i].name,fin[i].frank,fin[i].lnum+1,fin[i].lrank);
}
