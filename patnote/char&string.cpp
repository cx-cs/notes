#include<cstring>
#include<string>
#include<cstdio>
#include<iostream> 
using namespace std;
//һ�����ɣ�abc 123���Է���һ��string��
//return a+b<b+a
//string str=ch;
//strcpy(ch,str.c_str());
int main(){
	char s1[3][8]={"apple","orange","banana"};//cin.getline(s,100);��100��Ϊ'\0' 
	char s2[]="abcde";//�Զ���'\0' 
	printf("ԭ��%s\n",s2);
	printf("��b��ʼ%s\n",strchr(s2,'b'));//�Ҳ�������NULL
	char s3[20],s4[15]="";//�����ʼ��Ϊ�մ�������� 
    strcpy(s3,s2);//��s2���Ƶ�s3,����'\0' 
    strncpy(s4,s2,2);//��s2����2����s4������'\0' 
	cout<<"ȫ����:";puts(s3);
	cout<<"����2��:";puts(s4);
	printf("����%s��%s=",s2,s3);
	strcat(s3,s2);puts(s3);//�ӵ�s3����ע��Ҫ����
	printf("A+32=%c\n",'A'+32);
	cout<<"atoi:"<<atoi("24")<<endl;
	//cout<<"atoll:"<<atoll("9223372036854775807")<<endl;
	cout<<"atof:"<<atof("-3.14")<<endl;
	
	string t1="abc";//getline(cin,t);
	cout<<"stoi:"<<stoi("21")<<endl;
	cout<<"to_string:"<<to_string(3.14)<<endl;
	cout<<"ԭ��:"<<t1<<endl;
	t1.insert(0,2,'3');//����insert(pos,string),insert(it,itfirst,itlast)
	cout<<"0λ�ò���2��3:"<<t1<<endl; 
	t1.erase(0,2);//����erase[first,last)
	cout<<"0λ��ɾ��2��:"<<t1<<endl; 
	string t2=t1.substr(0,2);
	cout<<"0λ�ó���Ϊ2�ִ�:"<<t2<<endl;
	if(t1.find("bc",1)!=string::npos)
		cout<<"��1��ʼ��bc����ʼλ��:"<<t1.find("bc",1)<<endl;
	cout<<"ɾ��"<<t1<<"�ڶ���:";
	t1.erase(t1.begin()+1);
	cout<<t1<<endl;
	cout<<"��g:"<<((t1.find('g')==string::npos)?"�Ҳ���":"�ҵ���")<<endl;
	system("pause");
}
