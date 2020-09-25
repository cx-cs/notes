#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int graph[205][205];
int city[205],dis[205],happiness[205];//ÿ�����е��Ҹ�ֵ������ÿ������ʱ�ľ�����Ҹ�ֵ
int pathnum[205],past[205],pastnum[205];//����ÿ������ʱ�����·��������ÿ�����е�ǰ�����С�����ÿ������ǰ�����ĳ���
bool visit[205];//ÿ�������Ƿ񱻷��ʹ�
unordered_map<string,int>STOI;//�������ַ���ӳ�䵽����
string ITOS[205];//������ӳ�䵽�ַ���
int N,K;
void Dijkstra(int vend){
    while(!visit[vend]){//��δ�������յ����ʱ
        int v=-1,MIN=INT_MAX;
        for(int i=0;i<N;++i)//�ҳ���ǰδ�����ʵľ�����С�ĳ���
            if(!visit[i]&&MIN>dis[i]){
                v=i;
                MIN=dis[i];
            }
        if(v==-1)//ͼ����ֱͨ�ӷ���
            return;
        visit[v]=true;//��ǰ�����ѷ���
        for(int i=0;i<N;++i)//������ǰ�����ܵ���ĳ���
            if(!visit[i]&&graph[v][i]!=0){
            if(dis[i]>dis[v]+graph[v][i]){//�ܵ���ĵ�ǰ����δ�����ʹ��Ҿ���ɸ���
                dis[i]=dis[v]+graph[v][i];//���µ���ó��еľ���
                happiness[i]=happiness[v]+city[i];//���µ���ó��е��Ҹ�ֵ
                pastnum[i]=pastnum[v]+1;//���µ���ó���ǰ�������ĳ�����
                past[i]=v;//���µ���ó��е�ǰ������
                pathnum[i]=pathnum[v];//���µ���ó��е����·������
            }else if(dis[i]==dis[v]+graph[v][i]){//����ó���ʱ�ľ�����ó��д���ľ������
                pathnum[i]+=pathnum[v];//���µ���ó��е����·������
                if(happiness[i]<happiness[v]+city[i]||(happiness[i]==happiness[v]+city[i]&&pastnum[i]>pastnum[v]+1)){
                    past[i]=v;//���µ���ó��е�ǰ������
                    happiness[i]=happiness[v]+city[i];//���µ���ó��е��Ҹ�ֵ
                    pastnum[i]=pastnum[v]+1;//���µ���ó��е����·������
                }
            }
            }
    }
}
void DFS(int v){
    if(v==0){
        cout<<ITOS[v];
        return;
    }
    DFS(past[v]);
    cout<<"->"<<ITOS[v];
}
int main(){
    scanf("%d%d",&N,&K);
    cin>>ITOS[0];
    STOI[ITOS[0]]=0;
    for(int i=1;i<N;++i){
        cin>>ITOS[i];
        STOI[ITOS[i]]=i;
        cin>>city[i];
    }
    while(K--){
        int a;
        string s1,s2;
        cin>>s1>>s2>>a;
        graph[STOI[s1]][STOI[s2]]=graph[STOI[s2]][STOI[s1]]=a;
    }
    int vend=STOI["ROM"];//��ROM����Ϊ�յ����
    fill(dis+1,dis+N,INT_MAX);//�����ʼ��ΪINT_MAX
    pathnum[0]=1;//���������·����������Ϊ1
    Dijkstra(vend);
    printf("%d %d %d %d\n",pathnum[vend],dis[vend],happiness[vend],happiness[vend]/pastnum[vend]);
    DFS(vend);
    return 0;
}