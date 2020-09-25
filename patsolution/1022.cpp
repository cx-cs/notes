//本题最后要求输出书序号，可能有多个，把作者、年份等映射到（可能多个）书序号（用集合存，因为关键字） 
#include<map>
#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
map<string,set<int> >title,author,key,publisher,year;
void print(map<string,set<int> > &ma,string &tmp){//要引用不然超时 
	if(ma.count(tmp)==0)cout<<"Not Found"<<endl;
	else{
		for(set<int>::iterator it=ma[tmp].begin();it!=ma[tmp].end();it++)
			printf("%07d\n",*it);//坑点7位id 
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id;
		string ttitle,tauthor,tkey,tpublisher,tyear;
		scanf("%d\n", &id);//必须读掉换行不然被getline读走 
		getline(cin,ttitle);//书名有空格，getline读到换行符前 
		title[ttitle].insert(id);
		getline(cin,tauthor); 
		author[tauthor].insert(id);
		while(cin>>tkey){
			key[tkey].insert(id);
			if(getchar()=='\n')break;
		}
		getline(cin,tpublisher);
        publisher[tpublisher].insert(id);
        getline(cin,tyear);
        year[tyear].insert(id);
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int num;
		scanf("%d: ",&num);//scanf读取空格冒号 
		string tmp;
		getline(cin,tmp);
		cout<<num<<": "<<tmp<<endl;
		if(num==1)print(title,tmp);
		else if(num==2)print(author,tmp);
        else if(num==3)print(key,tmp);
        else if(num==4)print(publisher,tmp);
        else if(num==5)print(year,tmp);
	}
} 
