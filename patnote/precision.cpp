#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double round(double r)
{
	return (r>0.0)?floor(r+0.5):ceil(r-0.5);
}
int main(){
	double a=20.005;//������float 
	printf("%10.2f\n",a);//10����λ����Ĭ���������뵫������� 
	printf("%-10.2f\n",a+1e-8);//����� 
	cout<<round(2.5)<<" "<<round(-2.5)<<endl;//�������루����ֵ�ģ� 
	cout<<floor(2.5)<<" "<<floor(-2.5)<<endl;//���� 
	cout<<ceil(2.5)<<" "<<ceil(-2.5)<<endl;//���� 
	cout<<int(2.5)<<" "<<int(-2.5)<<endl;//�ض� 
	float b=20.005;
	cout<<(a==b?"yes":"no")<<endl;
	cout<<(fabs(a-b)<(1e-6)?"yes":"no")<<endl;
	//���ڵȼ���a>b+eps��С�ڵȼ���a<b-eps
	//���ڵ��ڵȼ���a>b-eps��С�ڵ��ڵȼ���a<b+eps
	system("pause");
}
