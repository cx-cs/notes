#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	float a[1001]={0};
	int num,t;
	float c;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d%f",&t,&c);
		a[t]=c;
	}
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d%f",&t,&c);
		a[t]+=c;//多项式相加
	}
	int cnt=0;
	for(int i=0;i<1001;i++)
		if(a[i]!=0)cnt++;
	printf("%d",cnt);
	for(int i=1000;i>=0;i--)
		if(a[i]!=0)printf(" %d %.1f",i,a[i]);
	system("pause");
}