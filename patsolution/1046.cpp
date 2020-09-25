#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> dis(n+1);
    int sum=0,left,right,cnt;
    for(int i=1;i<=n;i++){//d[i]为1到i+1距离，防止超时 
        int temp;
        scanf("%d",&temp);
        sum+=temp;
        dis[i]=sum;
    }
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++){
        scanf("%d %d",&left,&right);
        if(left>right)
            swap(left,right);
        int temp=dis[right-1]-dis[left-1];
        printf("%d\n",min(temp,sum-temp));//用sum得到反向距离 
    }
    return 0;
}
