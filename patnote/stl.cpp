#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
//ȫ�ֱ����;�̬�Զ���ʼ��Ϊ0������������в���
//��map��string ��set������stl�ڴ��������Ϻ����׳�ʱ�����ʹ��vector+sort��stl��������string[i]��
//���γ�-ѧ������ʱhash
//ֻҪ��������������hash
//stl������erase��������ȷɾ��
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,8,8,9,9};
	cout<<"int:";
	for(int i:a)cout<<i<<" ";
	int *b=max_element(a,a+5);
	cout<<endl<<"0��4λ�����Ԫ��:"<<*b<<endl;
	cout<<"�ڴ�С��������������е�һ�����ڻ����8�������±�:"<<lower_bound(a,a+10,8)-a<<endl;
	cout<<"�ڴ�С��������������е�һ������8�������±�:"<<upper_bound(a,a+10,8)-a<<endl;

	int c[10]={1,2,3,4,5,6,8,8,9,9};
	cout<<"ȥ��ǰ:";
	for(int i=0;i<10;i++)cout<<c[i];
	cout<<endl;
	cout<<"ȥ�ط���β��"<<unique(c,c+10)-c<<endl;
	cout<<"ȥ�غ�:";
	for(int i=0;i<10;i++)cout<<c[i];
	cout<<endl;
	
    typedef pair<int,int> PII;
    map<PII,int> m;
    PII p=make_pair(1,2);
	PII edge[10];//�ߵ�����,edge[i].first,edge[i].second
    
	vector<vector<int>> dp(len, vector<int>(len, 0));
    vector<int> v(5);//ֻҪ�趨��С���Զ���ʼ��Ϊ0
	for(int i=0;i<5;i++)v[i]=i+1;
    cout<<"vector:";
    for(auto i:v)cout<<i<<" ";
    v.erase(v.begin()+1);//������erase[first,last)
    cout<<endl<<"ɾ���ڶ���:";
	for(auto i:v)cout<<i<<" ";
    v.insert(v.begin()+1,2,-1);
    cout<<endl<<"�ڶ���λ�ò�2��-1:";
    for(auto i:v)cout<<i<<" ";
    reverse(v.begin()+1,v.end());
    cout<<endl<<"��ת�ڶ������:";
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
	cout<<"�����С10����ֵ3:";
	v.resize(10,3);
	for(auto i:v)cout<<i<<" ";
    cout<<endl;
    
    set<int> s;
	s.insert(1);s.insert(2);s.insert(3);
    cout<<"set:";
    for(auto i:s)cout<<i<<" ";
    s.erase(1);//������erase[first,last)
    cout<<endl<<"ɾ��1:";
    for(auto i:s)cout<<i<<" ";
    if(s.find(1)==s.end())cout<<endl<<"1 not found"<<endl;
    cout<<"���һ��Ԫ��"<<*s.rbegin()<<endl;

	map<int,int> mp;//erase(it),erase(key),erase[first,last)
	system("pause");
    return 0;
}
