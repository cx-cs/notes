//�������Ҫ���������ţ������ж���������ߡ���ݵ�ӳ�䵽�����ܶ��������ţ��ü��ϴ棬��Ϊ�ؼ��֣� 
#include<map>
#include<set>
#include<cstdio>
#include<iostream>
using namespace std;
map<string,set<int> >title,author,key,publisher,year;
void print(map<string,set<int> > &ma,string &tmp){//Ҫ���ò�Ȼ��ʱ 
	if(ma.count(tmp)==0)cout<<"Not Found"<<endl;
	else{
		for(set<int>::iterator it=ma[tmp].begin();it!=ma[tmp].end();it++)
			printf("%07d\n",*it);//�ӵ�7λid 
		}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int id;
		string ttitle,tauthor,tkey,tpublisher,tyear;
		scanf("%d\n", &id);//����������в�Ȼ��getline���� 
		getline(cin,ttitle);//�����пո�getline�������з�ǰ 
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
		scanf("%d: ",&num);//scanf��ȡ�ո�ð�� 
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
