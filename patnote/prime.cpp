#include<cstdio>
#include<cmath>
#include<ctime>
#include<vector>
using namespace std;
bool isprime(int n){
    if(n<=1)return false;
    int m=floor(sqrt(n)+0.5);
    for(int i=2;i<=m;i++)
        if(n%i==0)return false;
    return true;
}
bool is_prime(int n){//����
	if(n<=1)return false;
	for(int i=2;i*i<=n;i++)//������longlong��Ȼn�ܴ�ʱi*i����int���Ʊ为����ʱ
		if(n%i==0)return false;
	return true;
}
int main(){
	vector<int> prime(50000,1);//������ 
 	for(int i=2;i*i<50000;i++)
 		for(int j=2;j*i<50000;j++)
 			prime[j*i]=0;
	clock_t start=clock();
    for(int i=0;i<9999999;i++)
    	is_prime(i);
    clock_t end=clock();
    printf("time used=%fms\n",1000*(double)(end-start)/CLOCKS_PER_SEC);
	system("pause");
}
