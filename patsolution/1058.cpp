#include<cstdio>
using namespace std;
int main(){
    long long a,b,c,d,e,f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld",&a,&b,&c,&d,&e,&f);
    long long num=c+b*29+a*29*17+f+e*29+d*29*17;//相当于化为秒 
    long long g=num/(17*29);//小时 
    num=num%(17*29);//去掉小时后剩下秒数 
    printf("%lld.%lld.%lld",g,num/29,num%29);
    return 0;
}
