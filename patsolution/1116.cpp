#include<cstdio>
#include<cmath>
using namespace std;
int hashTable[10000];
bool isPrime(int n){
    if(n==1)return false;
    for(int i=2;i<=(int)sqrt(1.0*n);++i)
        if(n%i==0)return false;
    return true;
}
int main(){
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int a;
        scanf("%d",&a);
        hashTable[a]=i;
    }
    scanf("%d",&N);
    while(N--){
        int a;
        scanf("%d",&a);
        printf("%04d: ",a);
        if(hashTable[a]==0)
            printf("Are you kidding?\n");
        else if(hashTable[a]==-1)//元素值为-1，表示该ID号查询过
            printf("Checked\n");
        else{
            if(hashTable[a]==1)
                printf("Mystery Award\n");
            else if(isPrime(hashTable[a]))
                printf("Minion\n");
            else
                printf("Chocolate\n");
            hashTable[a]=-1;
        }
    }
    return 0;
}
