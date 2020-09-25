#include<iostream>
#include<cctype>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
long long converttoten(string n,long long radix){
	long long sum=0;
	int index=0;
	for(auto it=n.rbegin();it!=n.rend();it++){
		int tmp=isdigit(*it)?*it-'0':*it-'a'+10;
		sum+=tmp*pow(radix,index++);
	}
	return sum;
}
long long find(string n,long long ten){
	char t=*max_element(n.begin(),n.end());
	long long low=(isdigit(t)?t-'0':t-'a'+10)+1;//进制下界比最大那位大1 
	long long high=max(ten,low);//进制上界不是36而是那个十进制数
	while(low<=high){
		long long mid=(low+high)/2;
		long long tmp=converttoten(n,mid);
		if(ten==tmp)return mid;
		else if(tmp<0||tmp>ten)high=mid-1;//小于0是太大溢出了 
		else low=mid+1;
	}
	return -1;
}
int main(){
	string n1,n2;
	int tag;
	long long radix,findradix;
	cin>>n1>>n2>>tag>>radix;
	findradix=tag==1?find(n2,converttoten(n1,radix)):find(n1,converttoten(n2,radix));
	if(findradix==-1)cout<<"Impossible";
	else cout<<findradix;
	system("pause");
}
