#include<iostream>
#include<algorithm>
using namespace std;
int n,cnt,b[100];
struct node{
    int data,l,r,index,level;
}a[110];
bool cmp(node x,node y){
    if(x.level!=y.level)return x.level<y.level;
    return x.index<y.index;
}
void dfs(int root,int index,int level){
    if(a[root].l!=-1)dfs(a[root].l,index*2+1,level+1);
    a[root]={b[cnt++],a[root].l,a[root].r,index,level};//只是更新data，index和level 
    if(a[root].r!= -1)dfs(a[root].r,index*2+2,level+1);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].l>>a[i].r;
    for(int i=0;i<n;i++)
        cin>>b[i];
    sort(b,b+n);//先排序 
    dfs(0,0,0);
    sort(a,a+n,cmp);//按层，下标排序 
    for(int i=0;i<n;i++){
        if(i!=0)cout<< " ";
        cout<<a[i].data;
    }
    return 0;
}
