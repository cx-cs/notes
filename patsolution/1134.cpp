#include<vector>
#include<cstdio>
using namespace std;
int N,M,K;
int main(){
    scanf("%d%d",&N,&M);
    pair<int,int>edge[M];//�ߵ�����
    for(int i=0;i<M;++i)//��ȡ��
        scanf("%d%d",&edge[i].first,&edge[i].second);
    scanf("%d",&K);
    while(K--){
        int A,a;
        scanf("%d",&A);
        vector<bool> vertex(10005,false);
        while(A--){
            scanf("%d",&a);
            vertex[a]=true;//��vertex�����ж�ӦԪ����true
        }
        bool f=true;//��־���Ӧ��Ϊtrue����false
        for(int i=0;i<M&&f;++i)//�����ߵ�����
            if(!vertex[edge[i].first]&&!vertex[edge[i].second])//�б������˵���vertex�о�Ϊfalse
                f=false;//��fΪfalse
        printf("%s\n",f?"Yes":"No");//���
    }
    return 0;
}
