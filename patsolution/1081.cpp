#include<cstdio>
#include<cstdlib>//abs 
using namespace std;
long long gcd(long long a,long long b){return b==0?abs(a):gcd(b,a%b);}//շת����� 
int main() {
    long long n,a,b,suma=0,sumb=1,gcdvalue;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld/%lld",&a,&b);//����/ 
        gcdvalue=gcd(a,b);//���Լ�� 
        a=a/gcdvalue;//��ÿ����Լ�� 
        b=b/gcdvalue;
        suma=a*sumb+suma*b;//ͨ�ֺ���� 
        sumb=b*sumb;//ͨ�ֺ��ĸ 
        gcdvalue=gcd(suma,sumb);
        sumb=sumb/gcdvalue;//���Լ�� 
        suma=suma/gcdvalue;
    }
    long long integer=suma/sumb;//�������������� 
    suma=suma-(sumb*integer);//���� 
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