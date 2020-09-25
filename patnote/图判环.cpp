https://blog.csdn.net/dl962454/article/details/84575200
/*
ʱ�临�Ӷ�O(n)���ռ�O(n*n)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int edge[maxn][maxn];
bool vis[maxn];
int n;
int dfs(int u,int v)//��ǰ�ڵ�͸��ڵ�
{
    vis[u]=true;//��Ƿ��ʹ��ĵ�
    for(int i=1;i<=n;i++)
    {
        if(edge[u][i])//�����ڱ�
        {
            if(!vis[i]) dfs(i,u);
            else if(i!=v) return 1;//�ýڵ���ʹ������Ҳ��Ǹ��ڵ㣬���ɻ�
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
����ͼ�л�
ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n*n)
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
    vis[u]=vis2[u]=true;//��������Ƕ���Ϊ����
    for(int i=1;i<=n;i++)
    {
        if(edge[u][i])
        {
            if(!vis[i]) dfs(i);//δ������ļ�������
            else if(vis2[i]) flag=true;//�ҵ���
        }
    }
    vis2[u]=false;//���ݣ�����u�㿪ʼdfs��һ��·�㶼�������˿�ʼ����
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
            if(u!=v) edge[u][v]=w;//�����Ի�
        }
        dfs(1);
        if(flag) printf("Has Circle\n");
        else     printf("No Circle\n");
    }
    return 0;
}