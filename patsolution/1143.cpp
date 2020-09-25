#include<bits/stdc++.h>
using namespace std;
struct Node{//结点类
    int data,father,level;//权值、父节点在pre中的下标、深度
    Node(int d=0,int f=-1,int l=0):data(d),father(f),level(l){}
};
const int MAX=10005;
Node pre[MAX];
int n,m,in[MAX];
void createTree(int root,int left,int right,int father,int level){//确定每个结点的父节点和深度
    if(left>right)
        return;
    int i=left;
    while(i<=right&&in[i]!=pre[root].data)
        ++i;
    pre[root]=Node(pre[root].data,father,level);//确定当前子树根结点的父节点和深度
    createTree(root+1,left,i-1,root,level+1);//递归处理左子树
    createTree(root+1+i-left,i+1,right,root,level+1);//递归处理右子树
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&pre[i].data);
        in[i]=pre[i].data;
    }
    sort(in,in+n);//中序遍历序列
    createTree(0,0,n-1,-1,0);//父节点为-1 
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        int ia=n,ib=n;
        for(int i=0;i<n;++i){//找到两个结点在pre数组中的下标
            if(pre[i].data==a)
                ia=i;
            if(pre[i].data==b)
                ib=i;
        }
        if(ia==n&&ib==n){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(ia==n){
            printf("ERROR: %d is not found.\n",a);
        }else if(ib==n){
            printf("ERROR: %d is not found.\n",b);
        }else{
            bool f=true;//true表示a的深度更大注意a不是ia 
            if(pre[ia].level<pre[ib].level){//让ia指向深度更大的结点
                swap(ia,ib);
                f=false;
            }
            while(pre[ia].level>pre[ib].level)//将二者调整到同一深度
                ia=pre[ia].father;
            if(ia==ib){
                printf("%d is an ancestor of %d.\n",pre[ia].data,f?a:b);
            }else{
                while(ia!=ib){//ia,ib同时向上调整，直至二者指向同一结点
                    ia=pre[ia].father;
                    ib=pre[ib].father;
                }
                printf("LCA of %d and %d is %d.\n",a,b,pre[ia].data);
            }
        }
    }
    return 0;
}
