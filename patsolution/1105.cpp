#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int cmp(int a,int b){return a>b;}
int main(){
    int N,m,n,t=0;
    scanf("%d",&N);
    for(n=sqrt((double)N);n>=1;n--)//n肯定比m小 
        if(N%n==0){
            m=N/n;
            break;
        }
    vector<int> num(N);
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    sort(num.begin(),num.end(),cmp);
    vector<vector<int> > ans(m,vector<int>(n));//这里二维数组定义 
	int up=0,down=m-1,left=0,right=n-1,cnt=0;
    while(true){
        for(int j=left;j<=right;j++)ans[up][j]=num[cnt++];
        if(++up>down)break;
        for(int i=up;i<=down;i++)ans[i][right]=num[cnt++];
        if(--right<left)break;
        for(int j=right;j>=left;j--)ans[down][j]=num[cnt++];
        if(--down<up)break;
        for(int i=down;i>=up;i--)ans[i][left]=num[cnt ++];
        if(++left>right)break;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d",ans[i][j]);
            if(j!=n-1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
