#include<cstdio>
using namespace std;
int a[1001];
int main(){
    int n,m,temp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        a[temp]++;
    }
    for(int i=0;i<m;i++)
        if(a[i]&&a[m-i]&&(i!=m-i||a[i]>1)){
            printf("%d %d",i,m-i);
            return 0;
        }
    printf("No Solution");
    return 0;
}
