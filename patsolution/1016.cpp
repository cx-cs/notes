#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include<cstdio>
#include<string>
using namespace std;
struct node{
	int mon,day,h,m,status,time;
	string name;
};
int cmp1(node a,node b){
	return a.name==b.name?a.time<b.time:a.name<b.name;
}
//从0天0时0分计算 
double billsfrom0(node tmp,int* toll){
	double money=0;
	money+=60*tmp.day*toll[24]+tmp.m*toll[tmp.h];
	for(int i=0;i<tmp.h;i++)
		money+=60*toll[i];
	return money/100;
}
int main() {
	int toll[25]={0},n;
	for(int i=0;i<24;i++){
		cin>>toll[i];
		toll[24]+=toll[i];
	}
	cin>>n;
	vector<node> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].name;
		scanf("%d:%d:%d:%d",&v[i].mon,&v[i].day,&v[i].h,&v[i].m);
		v[i].time=v[i].day*24*60+v[i].h*60+v[i].m;
		string status;
		cin>>status;
		if(status=="on-line")v[i].status=1;
		else v[i].status=0;
	}
	sort(v.begin(),v.end(),cmp1);
	map<string,vector<node> >ma;
	for(int i=1;i<n;i++)
		if(v[i].name==v[i-1].name&&v[i].status==0&&v[i-1].status==1){
			ma[v[i].name].push_back(v[i-1]);
			ma[v[i].name].push_back(v[i]);
		}
	for(auto it=ma.begin();it!=ma.end();it++){//遍历map即可
		vector<node> tmp=it->second;
		cout<<it->first;
		printf(" %02d\n",tmp[0].mon);
		double total=0;
		for(int i=1;i<tmp.size();i+=2){
			double money=billsfrom0(tmp[i],toll)-billsfrom0(tmp[i-1],toll);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",tmp[i-1].day,tmp[i-1].h,tmp[i-1].m,tmp[i].day,tmp[i].h,tmp[i].m,tmp[i].time-tmp[i-1].time,money);
			total+=money;
		}
		printf("Total amount: $%.2f\n", total);
	}
}
