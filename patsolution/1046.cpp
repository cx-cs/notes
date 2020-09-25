#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> dis(n+1);
    int sum=0,left,right,cnt;
    for(int i=1;i<=n;i++){//d[i]Ϊ1��i+1���룬��ֹ��ʱ 
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
        printf("%d\n",min(temp,sum-temp));//��sum�õ�������� 
    }
    return 0;
}
