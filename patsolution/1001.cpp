#include<iostream>
#include<string>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	string s=to_string(a+b);
	int len=s.length();
	for(int i=0;i<len;i++){
		cout<<s[i];
		if((i!=0||s[0]!='-')&&i!=len-1&&(len-i-1)%3==0)
			cout<<",";
	}
	system("pause");
}
