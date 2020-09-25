#include<iostream>
#include<algorithm>
using namespace std;
string s;
void add(string t){ 
    int len=s.length(),enter=0;
    for(int i=0;i<len;i++) {//这里因为2个串互逆，直接往右进位最后再倒转 
        s[i]=s[i]+t[i]+enter-'0';//字符直接相加减去一个'0' 
        enter=0;
        if(s[i]>'9'){//最多进一位 
            s[i]=s[i]-10;
            enter=1;
        }
    }
    if(enter)s+='1';//右边补位 
    reverse(s.begin(),s.end());
}
int main(){
	int i,step;
	cin>>s>>step;
	for(i=0;i<step;i++){//包括一开始就是回文数 
		string t=s;
        reverse(t.begin(),t.end());//字符串反转 
        if(s==t)break;
        add(t);
    }
    cout<<s<<endl<<i;
}
