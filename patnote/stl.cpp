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
//全局变量和静态自动初始化为0，在类的声明中不会
//用map、string 、set这样的stl在大量数据上很容易超时，最好使用vector+sort的stl，名字用string[i]存
//按课程-学生输入时hash
//只要够大数组优先用hash
//stl可以用erase迭代器精确删除
using namespace std;
int main(){
	int a[10]={1,2,3,4,5,6,8,8,9,9};
	cout<<"int:";
	for(int i:a)cout<<i<<" ";
	int *b=max_element(a,a+5);
	cout<<endl<<"0到4位置最大元素:"<<*b<<endl;
	cout<<"在从小到大的排序数组中第一个大于或等于8的数字下标:"<<lower_bound(a,a+10,8)-a<<endl;
	cout<<"在从小到大的排序数组中第一个大于8的数字下标:"<<upper_bound(a,a+10,8)-a<<endl;

	int c[10]={1,2,3,4,5,6,8,8,9,9};
	cout<<"去重前:";
	for(int i=0;i<10;i++)cout<<c[i];
	cout<<endl;
	cout<<"去重返回尾部"<<unique(c,c+10)-c<<endl;
	cout<<"去重后:";
	for(int i=0;i<10;i++)cout<<c[i];
	cout<<endl;
	
    typedef pair<int,int> PII;
    map<PII,int> m;
    PII p=make_pair(1,2);
	PII edge[10];//边的数组,edge[i].first,edge[i].second
    
	vector<vector<int>> dp(len, vector<int>(len, 0));
    vector<int> v(5);//只要设定大小就自动初始化为0
	for(int i=0;i<5;i++)v[i]=i+1;
    cout<<"vector:";
    for(auto i:v)cout<<i<<" ";
    v.erase(v.begin()+1);//还可以erase[first,last)
    cout<<endl<<"删掉第二个:";
	for(auto i:v)cout<<i<<" ";
    v.insert(v.begin()+1,2,-1);
    cout<<endl<<"第二个位置插2个-1:";
    for(auto i:v)cout<<i<<" ";
    reverse(v.begin()+1,v.end());
    cout<<endl<<"反转第二到最后:";
    for(auto i:v)cout<<i<<" ";
    cout<<endl;
	cout<<"重设大小10并赋值3:";
	v.resize(10,3);
	for(auto i:v)cout<<i<<" ";
    cout<<endl;
    
    set<int> s;
	s.insert(1);s.insert(2);s.insert(3);
    cout<<"set:";
    for(auto i:s)cout<<i<<" ";
    s.erase(1);//还可以erase[first,last)
    cout<<endl<<"删掉1:";
    for(auto i:s)cout<<i<<" ";
    if(s.find(1)==s.end())cout<<endl<<"1 not found"<<endl;
    cout<<"最后一个元素"<<*s.rbegin()<<endl;

	map<int,int> mp;//erase(it),erase(key),erase[first,last)
	system("pause");
    return 0;
}
