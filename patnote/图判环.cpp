https://blog.csdn.net/dl962454/article/details/84575200
/*
时间复杂度O(n)，空间O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int edge[maxn][maxn];
bool vis[maxn];
int n;
int dfs(int u,int v)//当前节点和父节点
{
    vis[u]=true;//标记访问过的点
    for(int i=1;i<=n;i++)
    {
        if(edge[u][i])//若存在边
        {
            if(!vis[i]) dfs(i,u);
            else if(i!=v) return 1;//该节点访问过，并且不是父节点，构成环
        }
    }
    return 0;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(edge,0,sizeof(edge));
        memset(vis,false,sizeof(vis));
        int u,v;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            if(u==v) continue;
            edge[u][v]=edge[v][u]=1;
        }
        if(dfs(1,0))
            printf("The Graph Has Circle\n");
        else
            printf("No Circle\n");
    }
    return 0;
}
/*
有向图判环
时间复杂度O(n),空间复杂度O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
typedef long long LL;
int edge[maxn][maxn];
bool vis[maxn],vis2[maxn];
int n,m;
bool flag;
void init()
{
    flag=false;
    memset(edge,0,sizeof(edge));
    memset(vis,false,sizeof(vis));
    memset(vis2,0,sizeof(vis2));
}
void dfs(int u)
{
    vis[u]=vis2[u]=true;//将两个标记都置为访问
    for(int i=1;i<=n;i++)
    {
        if(edge[u][i])
        {
            if(!vis[i]) dfs(i);//未访问完的继续访问
            else if(vis2[i]) flag=true;//找到环
        }
    }
    vis2[u]=false;//回溯，当从u点开始dfs的一条路点都访问完了开始回溯
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u!=v) edge[u][v]=w;//避免自环
        }
        dfs(1);
        if(flag) printf("Has Circle\n");
        else     printf("No Circle\n");
    }
    return 0;
}