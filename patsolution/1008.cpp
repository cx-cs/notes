#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int time=0;
	int cur=0;
	int next;
	for(int i=0;i<n;i++){
		cin>>next;
		time=time+5+((next>cur)?6*(next-cur):4*(cur-next));
		cur=next;
	}
	cout<<time;
}
