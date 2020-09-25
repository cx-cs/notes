#include<cctype>
#include<climits>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    printf("aaaa\rbbb\n");//回行首,enter为\r\n,但\r不会读取 
    //isblank（space、\t）
	//isspace（space、\t、\r、\n）
	//isalnum 字母数字
	//isalpha 字母
	//isdigit 数字
	//isupper 是大写字母
	//islower 是小写字母
	cout<<INT_MAX<<" "<<INT_MIN<<" "<<LLONG_MAX<<endl;
	cout<<((1<<31)-1)<<" "<<-((1<<31))<<" "<<((1LL<<63)-1)<<endl;
	system("pause");
    return 0;
}
