#include<iostream>
using namespace std;
int main(){
	cout<<"#";
	for(int i=0;i<3;i++){
		char a[100]={0};
		int num,index=0;
		cin>>num;
		if(num==0){//进制转换特殊情况 
			cout<<"00";
			continue;
		}
		while(num!=0){
			int tmp=num%13;
			if(tmp>=10)a[index++]=tmp-10+'A';
			else a[index++]=tmp+'0';
			num/=13;
		}
		if(index==1)cout<<"0";
		for(int j=index-1;j>=0;j--)
			cout<<a[j];
	}
}
