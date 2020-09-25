#include<cstdio>
#include<cstdlib>//abs 
using namespace std;
long long gcd(long long a,long long b){return b==0?abs(a):gcd(b,a%b);}//辗转相除法 
int main() {
    long long n,a,b,suma=0,sumb=1,gcdvalue;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&a,&b);//读掉/ 
        gcdvalue=gcd(a,b);//最大公约数 
        a=a/gcdvalue;//把每个数约分 
        b=b/gcdvalue;
        suma=a*sumb+suma*b;//通分后分子 
        sumb=b*sumb;//通分后分母 
        gcdvalue=gcd(suma,sumb);
        sumb=sumb/gcdvalue;//最后约分 
        suma=suma/gcdvalue;
    }
    long long integer=suma/sumb;//带分数整数部分 
    suma=suma-(sumb*integer);//分子 
    if(integer!=0){
        printf("%lld",integer);
        if(suma!=0)printf(" ");
    }
    if(suma!=0)
        printf("%lld/%lld",suma,sumb);
    if(integer==0&&suma==0)
        printf("0");
    return 0;
}
