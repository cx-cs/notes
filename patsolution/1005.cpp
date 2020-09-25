#include<iostream>
#include<string>
using namespace std;
int main(){
	int sum=0;
	string t;
	cin>>t;
	for(int i=0;i<t.length();i++)
		sum=sum+t[i]-'0';
	string s[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	t=to_string(sum);
	for(int i=0;i<t.length();i++)
		cout<<(i==0?"":" ")<<s[t[i]-'0'];
	system("pause");
}
