#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	float a[1001]={0};
	float b[2001]={0};
	int k1;
	cin>>k1;
	for(int i=0;i<k1;i++){
		int t;
		float c;
		cin>>t>>c;
		a[t]=c;
	}
	int k2;
	cin>>k2;
	for(int i=0;i<k2;i++){
		int t;
		float c;
		cin>>t>>c;
		for(int j=0;j<=1000;j++)
			if(a[j]!=0)b[t+j]=b[t+j]+a[j]*c;
	}
	int k=0;
	for(int i=0;i<=2000;i++)
		if(b[i]!=0)k++;
	cout<<k;
	for(int i=2000;i>=0;i--)
		if(b[i]!=0)printf(" %d %.1f",i,b[i]);
}
