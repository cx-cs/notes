#include<iostream>
using namespace std;
#define maxn 100
int c[maxn];
int lowbit(int t){//t���ұߵ�1�ͺ����0��ʮ���� 
return t&(-t);
}

void update(int x,int v){//�±�+��ֵ 
    for(int i=x;i<maxn;i+=lowbit(i))//�ܸ���c[i]����c[i+lowbit[i]]
        c[i]+=v;
}
int getsum(int x){//ǰx����֮�� 
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i))//c[i]����lowbit(i)��,sum(1,x)=sum(1,x-lowbit(x))+c[x]
        sum+=c[i];
    return sum;
}

void update(int x,int v){//��ֵ+1 
    for(int i=x;i<maxn;i+=lowbit(i))//�ܸ���c[i]����c[i+lowbit[i]]
        c[i]+=v;
}
int getsum(int x){//С�ڵ���x�������ִ���֮�� 
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i))//c[i]����lowbit(i)��,sum(1,x)=sum(1,x-lowbit(x))+c[x]
        sum+=c[i];
    return sum;
} 
//����������������ÿ���������֮�ͻ������С�����ĸ����������������ұߵĻ������鷴����������С� 


//�����ʱ��̫��Ҫӳ�䵽1��N��Ҫ���ִ�С˳�����ýṹ����ֵ������˳���±꣬��ֵ��С����
//val 8 6 7 8
//pos 0 1 2 3
//�����:
//val 6 7 8 8
//pos 1 2 0 3
//A[1]=1,A[2]=2,A[0]=3,A[4]=3����Ϊ��ǰһ�����)��������3123 
//���k����������ַ���get(i)>=k��������
