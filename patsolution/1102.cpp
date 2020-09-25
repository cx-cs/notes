#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node{
    int id,l,r,index,level;
}a[100];
vector<node> v1;
//题意是左右倒转 
void dfs(int root,int index,int level){
    if(a[root].r!=-1)dfs(a[root].r,index*2+2,level+1);
    v1.push_back({root,0,0,index,level});
    if(a[root].l!=-1)dfs(a[root].l,index*2+1,level+1);
}
bool cmp(node a,node b){
    if(a.level!=b.level)return a.level<b.level;
    return a.index>b.index;//左右 
}
int main(){
    int n,have[100]={0},root=0;
    cin>>n;
    for(int i=0;i<n;i++){
        a[i].id=i ;
        string l,r;
        cin>>l>>r;
        if(l!="-"){
        	char tmp[5]="";
        	int ttmp;
        	l.copy(tmp,l.length());
        	sscanf(tmp,"%d",&ttmp);
            a[i].l=ttmp;
            have[ttmp]=1;//用来记录有没有上级 
        }else
            a[i].l=-1;
        if(r!="-"){
            char tmp[5]="";
        	int ttmp;
        	r.copy(tmp,r.length());
        	sscanf(tmp,"%d",&ttmp);
            a[i].r=ttmp;
            have[ttmp]=1;
        }else
            a[i].r=-1;
    }
    while(have[root]==1)root++;//找根结点 
    dfs(root,0,0);
    vector<node> v2(v1);
    sort(v2.begin(),v2.end(),cmp);//层序就是按层和下标排序 
    for(int i=0;i<v2.size();i++){
        if(i!=0)cout<<" ";
        cout<<v2[i].id;
    }
    cout<<endl;
    for(int i=0;i<v1.size();i++){
        if(i!=0)cout<<" ";
        cout<<v1[i].id;
    }
    return 0;
}
