#include<iostream>
#include<cmath>
using namespace std;
int is_prime(int n){
	if(n<=1)return 0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)return 0;
	return 1;
}
int reverse(int n,int d){
	int s[100];
	int len=0,sum=0;
	while(n!=0){
		s[len++]=n%d;
		n=n/d;
	}
	int index=0;
	for(int i=len-1;i>=0;i--)
		sum+=s[index++]*pow(d,i);
	return sum;
}
int main(){
	int n,d;
	while(1){
		cin>>n;
		if(n<0)return 0;
		cin>>d;
		if(is_prime(n)&&is_prime(reverse(n,d)))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
