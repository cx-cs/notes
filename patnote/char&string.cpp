#include<cstring>
#include<string>
#include<cstdio>
#include<iostream> 
using namespace std;
//一个技巧：abc 123可以放在一个string中
//return a+b<b+a
//string str=ch;
//strcpy(ch,str.c_str());
int main(){
	char s1[3][8]={"apple","orange","banana"};//cin.getline(s,100);第100个为'\0' 
	char s2[]="abcde";//自动加'\0' 
	printf("原串%s\n",s2);
	printf("从b开始%s\n",strchr(s2,'b'));//找不到返回NULL
	char s3[20],s4[15]="";//必须初始化为空串否则出错 
    strcpy(s3,s2);//把s2复制到s3,包括'\0' 
    strncpy(s4,s2,2);//把s2复制2个到s4不包括'\0' 
	cout<<"全复制:";puts(s3);
	cout<<"复制2个:";puts(s4);
	printf("连接%s和%s=",s2,s3);
	strcat(s3,s2);puts(s3);//接到s3后面注意要够大
	printf("A+32=%c\n",'A'+32);
	cout<<"atoi:"<<atoi("24")<<endl;
	//cout<<"atoll:"<<atoll("9223372036854775807")<<endl;
	cout<<"atof:"<<atof("-3.14")<<endl;
	
	string t1="abc";//getline(cin,t);
	cout<<"stoi:"<<stoi("21")<<endl;
	cout<<"to_string:"<<to_string(3.14)<<endl;
	cout<<"原串:"<<t1<<endl;
	t1.insert(0,2,'3');//还有insert(pos,string),insert(it,itfirst,itlast)
	cout<<"0位置插入2个3:"<<t1<<endl; 
	t1.erase(0,2);//还有erase[first,last)
	cout<<"0位置删掉2个:"<<t1<<endl; 
	string t2=t1.substr(0,2);
	cout<<"0位置长度为2字串:"<<t2<<endl;
	if(t1.find("bc",1)!=string::npos)
		cout<<"从1开始找bc的起始位置:"<<t1.find("bc",1)<<endl;
	cout<<"删掉"<<t1<<"第二个:";
	t1.erase(t1.begin()+1);
	cout<<t1<<endl;
	cout<<"找g:"<<((t1.find('g')==string::npos)?"找不到":"找到了")<<endl;
	system("pause");
}
