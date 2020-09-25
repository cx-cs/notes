#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int rank,id,total;//结构体赋初值 
    vector<int> score;
    int passnum;
    bool isshown;
	node():total(0),passnum(0),isshown(false){};
};
bool cmp1(node a,node b){
    if(a.total!=b.total)
        return a.total>b.total;
    else if(a.passnum!=b.passnum)
        return a.passnum>b.passnum;
    else
        return a.id<b.id;
}
int main(){
    int n,k,m,id,num,score;
    scanf("%d %d %d",&n,&k,&m);
    vector<node> v(n+1);
    for(int i=1;i<=n;i++)
        v[i].score.resize(k+1,-1);//resize同时赋值 
    vector<int> full(k+1);
    for(int i=1;i<=k;i++)
        scanf("%d",&full[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&id,&num,&score);
        v[id].id=id;
        if(score!=-1)//只要有一个通过编译就输出 
            v[id].isshown=true;
        else score=0;
        v[id].score[num]=max(v[id].score[num],score);//存最大分数 
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(v[i].score[j]!=-1)
                v[i].total+=v[i].score[j];
            if(v[i].score[j]==full[j])
                v[i].passnum++;
        }
    }
    sort(v.begin()+1,v.end(),cmp1);
    for(int i=1;i<=n;i++){
        v[i].rank=i;
        if(i!=1&&v[i].total==v[i-1].total)//排名 
            v[i].rank=v[i-1].rank;
    }
    for(int i=1;i<=n;i++)
        if(v[i].isshown==true){
            printf("%d %05d %d",v[i].rank,v[i].id,v[i].total);
            for(int j=1;j<=k;j++){
                if(v[i].score[j]!=-1)
                    printf(" %d",v[i].score[j]);
                else printf(" -");
            }
            printf("\n");
        }
	system("pause");
    return 0;
}
