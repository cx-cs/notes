#include<cstdio>
#include<cstring>
//long long只有19位 
using namespace std;
int main(){
	int times[10]={0};
	char a[21];
	scanf("%s",a);
	int flag=0;
	for(int i=strlen(a)-1;i>=0;i--){
		int num=a[i]-'0';//字符转数字
		times[num]++;
		num=2*num+flag;
		flag=0;
		if(num>=10){
			num-=10;
			flag=1;
		}
		a[i]=num+'0';
		times[num]--;
	}
	int j;
	for(j=0;j<10;j++)
		if(times[j]!=0)break;
	if(j==10)printf("Yes\n");
	else printf("No\n");
	if(flag==1)printf("1");
	printf("%s",a);
}
