#include<cstdio>
#include<vector>
using namespace std;
vector<int> in,pre,post;
//查找得到的先根序列中根节点的下一结点在后根序列中的位置正好等于right-1则不唯一，因为这说明只有一个孩子不知道左右
bool unique=true;
void inOrder(int root,int left,int right){
    if(left>=right){
        if(left==right)//left==right，只有一个结点
            in.push_back(pre[root]);//压入中根序列中
        return;
    }
    int i=left;
    while(i<right&&post[i]!=pre[root+1])//查找先根序列中根节点的下一结点在后根序列中的位置
        ++i;
    if(i==right-1)
        unique=false;//树的形态不唯一
    inOrder(root+1,left,i);//i其实是左根
    in.push_back(pre[root]);
    inOrder(root+i-left+2,i+1,right-1);//右子树
}
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n),post.resize(n);
	for(int i=0;i<n;i++) 
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	inOrder(0,0,n-1);
	printf("%s\n%d",unique==true?"Yes":"No",in[0]);
	for(int i=1;i<in.size();i++)
		printf(" %d",in[i]);
	printf("\n");
	return 0;
}
