#include<cstdio>
using namespace std;
int main(){
	char s[]="WTL";
	float a[3],sum=1;
	for(int i=0;i<3;i++){
		int index=0;
		for(int j=0;j<3;j++){
			scanf("%f",&a[j]);
			if(a[j]>a[index]){
				index=j;
			}
		}
		printf("%c ",s[index]);
		sum*=a[index];
	}
	sum=(sum*0.65-1)*2;
	printf("%.2f",sum);
}
