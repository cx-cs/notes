#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define INF 0x3fffffff
typedef struct node{				//结点定义 
	int data;
	struct node *right,*left;
}Node;
vector<int> inor,layor;				//中序和层序序列 
unordered_map<int,int> inmp,laymp;	//序列与其下标的映射，（建立映射可以减少递归时候查找序列的次数） 
Node *creat(int il,int ir){			//建树函数 ，il表示中序序列的左端，ir便是中序序列的右端 
	if(il>ir) return NULL;			//如果树中序列长度为0，表示到了空结点 
	int min=INF,id;					//min表示中序序列中的元素在层序中下标最小的那个，其中序的下标 
	for(int i=il;i<=ir;i++){		//遍历中序序列，找出对应层序中下边最小的元素 
		if(laymp[inor[i]]<min){
			min=laymp[inor[i]];
		}
	}
	Node *root=new node;			
	root->data=layor[min];			//中序序列中 层序中下标最小的便是根 
	id=inmp[root->data];			//获得根在中序的位置，划分为左子树和右子树 
	root->left=creat(il,id-1);		//递归左子树 
	root->right=creat(id+1,ir);		//递归右子树 
	return root;					//返回当前子树的根 
}
void preorder(Node *root){			//递归的先序遍历函数 
	if(root==NULL) return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main(void){

	int n;
	cin>>n;
	inor.resize(n); layor.resize(n);//读入元素个数并初始化 
	for(int i=0;i<n;i++){			//读入中序序列并完成映射 
		cin>>inor[i];
		inmp[inor[i]]=i;
	} 
	for(int i=0;i<n;i++){			//读入层序序列并完成映射 
		cin>>layor[i];
		laymp[layor[i]]=i;
	} 
	Node *root=creat(0,n-1);		//建树 
	preorder(root);					//先序遍历，验证树的结构 
	return 0;
} 
