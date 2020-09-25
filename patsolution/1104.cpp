#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    double sum=0.0,temp;
    for(int i=1;i<=n;i++){ 
        scanf("%lf",&temp);
        sum=sum+temp*i*(n-i+1);
    }
    printf("%.2f",sum);
    return 0;
}
