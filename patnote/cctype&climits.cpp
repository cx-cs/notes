#include<cctype>
#include<climits>
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    printf("aaaa\rbbb\n");//������,enterΪ\r\n,��\r�����ȡ 
    //isblank��space��\t��
	//isspace��space��\t��\r��\n��
	//isalnum ��ĸ����
	//isalpha ��ĸ
	//isdigit ����
	//isupper �Ǵ�д��ĸ
	//islower ��Сд��ĸ
	cout<<INT_MAX<<" "<<INT_MIN<<" "<<LLONG_MAX<<endl;
	cout<<((1<<31)-1)<<" "<<-((1<<31))<<" "<<((1LL<<63)-1)<<endl;
	system("pause");
    return 0;
}
