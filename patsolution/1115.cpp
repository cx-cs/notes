#include<cstdio>
#include<vector>
using namespace std;
struct node{
    int v;
    node *left=NULL,*right=NULL;
    node(int d):v(d){};
};
void insert(node* &root,int v){//必须要引用 
    if(root==NULL){
        root=new node(v); 
        return;
    }
    if(v<=root->v)insert(root->left,v);
    else insert(root->right,v);
}
vector<int> num(1000);
int maxdepth=-1;
void dfs(node* root,int depth){
    if(root==NULL){
        maxdepth=max(depth,maxdepth);
        return;
    }
    num[depth]++;
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);
}
int main(){
    int n,t;
    scanf("%d",&n);
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        insert(root,t);
    }
    dfs(root,0);
    printf("%d + %d = %d",num[maxdepth-1],num[maxdepth-2],num[maxdepth-1]+num[maxdepth-2]);
    return 0;
}
