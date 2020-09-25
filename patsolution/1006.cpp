#include<iostream>
#include<string>
#include<cstdio> 
#include<climits>
using namespace std;
int main(){
	int n,early=INT_MAX,late=INT_MIN;
	string unlock,lock;//Ö»Òª2¸ö×Ö·û´®£» 
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		int h1,h2,m1,m2,s1,s2;
		scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		int earl=h1*3600+m1*60+s1;
		int lat=h2*3600+m2*60+s2;
		if(earl<=early){
			unlock=t;
			early=earl;
		}
		if(lat>=late){
			lock=t;
			late=lat;
		}
	}
	cout<<unlock<<" "<<lock;
	system("pause");
}
