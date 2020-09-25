#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,ans=0;
    scanf("%d",&N);
    int left=N/10,right=0,current=N%10;
    for (int i=1;right!=N;i*=10) {
        ans+=left*i+(current==0?0:current==1?(right+1):i);
        right+=current*i;
        current=left%10;
        left/=10;
    }
    printf("%d",ans);
    return 0;
}
