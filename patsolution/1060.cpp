#include<iostream>
#include<string>
using namespace std;
int f(const string&s,string&temp,int N){
    int point=s.size(),index=-1;//pointС�����λ�ã���ʼ��Ϊ���һλ��indexָʾs�е�һλ�������ֵ�λ�ã���ʼ��Ϊ-1
    for(int i=0;i<s.size();i++)
        if(s[i]=='.')//�ҳ�С����λ��
            point=i;
        else if(index!=-1&&temp.size()<N)//��Ч���� 
            temp+=s[i];
        else if(index==-1&&s[i]!='0'){//�ҵ��ַ���s��һλ�������ֵ�λ��
            index=i;
            temp+=s[i];
        }
    while(temp.size()<N)
        temp+="0";//���ַ���ĩβ���㹻��0��֤��Nλ��Ч����
    if(index==-1)//û���ҵ��������֣�˵���ַ���s��ʾ������0
        return 0;
    point-=index;//С����λ�ü�ȥ��һλ��������λ�õõ�ָ��
    return point<0?point+1:point;//��ǰpointΪ����������point+1�����򷵻�point
}
int main(){
    int N;
    string A,B,Atemp="",Btemp="";
    cin>>N>>A>>B;//��ȡ����
    int Aexp=f(A,Atemp,N),Bexp=f(B,Btemp,N);
    if(Aexp==Bexp&&Atemp==Btemp)//��Ч���ֺ�ָ�������
        cout<<"YES 0."<<Atemp<<"*10^"<<Aexp;
    else
        cout<<"NO 0."<<Atemp<<"*10^"<<Aexp<<" 0."<<Btemp<<"*10^"<<Bexp;
    return 0;
}
