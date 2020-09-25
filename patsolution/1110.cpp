#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int l,r;
}a[100];
int maxn=-1,ans;
void dfs(int root,int index){//index表示第几个结点 
    if(index>maxn){
        maxn=index;
        ans=root;
    }
    if(a[root].l!=-1)dfs(a[root].l,index*2);//子节点 
    if(a[root].r!=-1)dfs(a[root].r,index*2+1); 
}
int main(){
    int n,root=0,have[100]={0};//有根 
    cin>>n;
    for(int i=0;i<n;i++){
        string l,r;
        cin>>l>>r;
        if(l=="-"){
            a[i].l=-1;
        }else{
        	char tmp[5]="";
        	int ttmp;
        	l.copy(tmp,l.length());
        	sscanf(tmp,"%d",&ttmp);
            a[i].l=ttmp;
            have[ttmp]=1;
        }
        if(r=="-"){
            a[i].r=-1;
        }else{
            char tmp[5]="";
        	int ttmp;
        	r.copy(tmp,r.length());
        	sscanf(tmp,"%d",&ttmp);
            a[i].r=ttmp;
            have[ttmp]=1;
        }
    }
    while(have[root]!=0)root++;//找没根的就是根 
    dfs(root,1);
    if(maxn==n)//完全二叉树必然相等 
        cout<<"YES "<<ans;
    else
        cout<<"NO "<<root;
    return 0;
}

