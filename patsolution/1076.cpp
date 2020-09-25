#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int N,L,K;
vector<int> graph[1005];//ͼ
int BFS(int v){//������ȱ���
    int num=0,level[1005]={0};//level��ʾ�û�ת��ʱ������ת������
    bool visit[1005]={false};
    queue<int> q;
    q.push(v);
    visit[v]=true;
    while(!q.empty()){
        v=q.front();
        q.pop();
        for(int j=0;j<graph[v].size();j++){
        	int i=graph[v][j];
            if(!visit[i]&&level[v]<L){//���û�з��ʹ���ת������<L�����������Ϣ
                ++num;
                visit[i]=true;
                level[i]=level[v]+1;
                q.push(i);
            }
        }
    }
    return num;//����ת������
}
int main(){
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;++i){
        int num,a;
        scanf("%d",&num);
        while(num--){
            scanf("%d",&a);
            graph[a].push_back(i);
        }
    }
    scanf("%d",&K);
    while(K--){
        int a;
        scanf("%d",&a);
        printf("%d\n",BFS(a));
    }
    return 0;
}
