#include<iostream>
#include<algorithm>
using namespace std;
string s;
void add(string t){ 
    int len=s.length(),enter=0;
    for(int i=0;i<len;i++) {//������Ϊ2�������棬ֱ�����ҽ�λ����ٵ�ת 
        s[i]=s[i]+t[i]+enter-'0';//�ַ�ֱ����Ӽ�ȥһ��'0' 
        enter=0;
        if(s[i]>'9'){//����һλ 
            s[i]=s[i]-10;
            enter=1;
        }
    }
    if(enter)s+='1';//�ұ߲�λ 
    reverse(s.begin(),s.end());
}
int main(){
	int i,step;
	cin>>s>>step;
	for(i=0;i<step;i++){//����һ��ʼ���ǻ����� 
		string t=s;
        reverse(t.begin(),t.end());//�ַ�����ת 
        if(s==t)break;
        add(t);
    }
    cout<<s<<endl<<i;
}
