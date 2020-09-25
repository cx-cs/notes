#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double round(double r)
{
	return (r>0.0)?floor(r+0.5):ceil(r-0.5);
}
int main(){
	double a=20.005;//不能用float 
	printf("%10.2f\n",a);//10是总位数，默认四舍五入但是有误差 
	printf("%-10.2f\n",a+1e-8);//左对齐 
	cout<<round(2.5)<<" "<<round(-2.5)<<endl;//四舍五入（绝对值的） 
	cout<<floor(2.5)<<" "<<floor(-2.5)<<endl;//向下 
	cout<<ceil(2.5)<<" "<<ceil(-2.5)<<endl;//向上 
	cout<<int(2.5)<<" "<<int(-2.5)<<endl;//截断 
	float b=20.005;
	cout<<(a==b?"yes":"no")<<endl;
	cout<<(fabs(a-b)<(1e-6)?"yes":"no")<<endl;
	//大于等价于a>b+eps，小于等价于a<b-eps
	//大于等于等价于a>b-eps，小于等于等价于a<b+eps
	system("pause");
}
