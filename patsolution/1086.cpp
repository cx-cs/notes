#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int> pre,in,post,value;
void postorder(int root,int start,int end){
    if(start>end)return;
    int i=start;
    while(i<end&&in[i]!=pre[root])i++;//i是中序根位置 
    postorder(root+1,start,i-1);//中序左子树根在前序中的下标是前序根+1 
    postorder(root+1+i-start,i+1,end);//中序右子树根在前序中的下标是前序根加上左子树长度+2 
    post.push_back(pre[root]);//这个是根 
}
int main(){
    int n;
    scanf("%d",&n);
    char str[5];
    stack<int> s;
    int key=0;
    while(~scanf("%s",str)){
        if(strlen(str)==4){
            int num;
            scanf("%d",&num);
            value.push_back(num);
            pre.push_back(key);//前序 
            s.push(key++);
        }else{
            in.push_back(s.top());//中序 
            s.pop();
        }
    }
    postorder(0,0,n-1);//由前序中序构造后序 
    printf("%d",value[post[0]]);
    for(int i=1;i<n;i++)
        printf(" %d",value[post[i]]);
    return 0;
}
