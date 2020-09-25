#include<vector>
#include<cstdio>
using namespace std;
int N,M,K;
int main(){
    scanf("%d%d",&N,&M);
    pair<int,int>edge[M];//边的数组
    for(int i=0;i<M;++i)//读取边
        scanf("%d%d",&edge[i].first,&edge[i].second);
    scanf("%d",&K);
    while(K--){
        int A,a;
        scanf("%d",&A);
        vector<bool> vertex(10005,false);
        while(A--){
            scanf("%d",&a);
            vertex[a]=true;//将vertex数组中对应元素置true
        }
        bool f=true;//标志输出应该为true还是false
        for(int i=0;i<M&&f;++i)//遍历边的数组
            if(!vertex[edge[i].first]&&!vertex[edge[i].second])//有边两个端点在vertex中均为false
                f=false;//置f为false
        printf("%s\n",f?"Yes":"No");//输出
    }
    return 0;
}
