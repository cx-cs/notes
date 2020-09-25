#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long LL;
int main(){
   int n;
   scanf("%d",&n);
   int len=0,start,tmplen,tmpstart,tmpn;
   for(LL i=2;i*i<=n;i++){
	   tmpstart=i;
	   tmplen=0;
	   tmpn=n;
	   while(tmpn%(i+tmplen)==0){
		   tmpn=tmpn/(i+tmplen);
		   tmplen++;
	   }
	   if(len<tmplen){
		   len=tmplen;
		   start=tmpstart;
	   }
   }
   if(len==0){
	   printf("%d\n%d",1,n);
	   system("pause");
	   return 0;
   }
   printf("%d\n",len);
   while(len--)
	   printf("%d%s",start++,len==0?"":"*");
	system("pause");
}