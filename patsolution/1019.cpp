#include<iostream>
using namespace std;
int main(){
	int n,b;
	cin>>n>>b;
	int a[100],len=0;
	while(n!=0){
		a[len++]=n%b;
		n=n/b;
	}
	int yes=1;
	for(int i=0;i<len/2;i++)
		if(a[i]!=a[len-i-1]){
			yes=0;
			break;
		}
	if(yes)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	if(len==0)cout<<"0";//¿Ó 
	for(int i=len-1;i>=0;i--){
		cout<<a[i];
		if(i!=0)cout<<" ";
	}
}
