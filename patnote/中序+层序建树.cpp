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
typedef struct node{				//��㶨�� 
	int data;
	struct node *right,*left;
}Node;
vector<int> inor,layor;				//����Ͳ������� 
unordered_map<int,int> inmp,laymp;	//���������±��ӳ�䣬������ӳ����Լ��ٵݹ�ʱ��������еĴ����� 
Node *creat(int il,int ir){			//�������� ��il��ʾ�������е���ˣ�ir�����������е��Ҷ� 
	if(il>ir) return NULL;			//����������г���Ϊ0����ʾ���˿ս�� 
	int min=INF,id;					//min��ʾ���������е�Ԫ���ڲ������±���С���Ǹ�����������±� 
	for(int i=il;i<=ir;i++){		//�����������У��ҳ���Ӧ�������±���С��Ԫ�� 
		if(laymp[inor[i]]<min){
			min=laymp[inor[i]];
		}
	}
	Node *root=new node;			
	root->data=layor[min];			//���������� �������±���С�ı��Ǹ� 
	id=inmp[root->data];			//��ø��������λ�ã�����Ϊ�������������� 
	root->left=creat(il,id-1);		//�ݹ������� 
	root->right=creat(id+1,ir);		//�ݹ������� 
	return root;					//���ص�ǰ�����ĸ� 
}
void preorder(Node *root){			//�ݹ������������� 
	if(root==NULL) return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
int main(void){

	int n;
	cin>>n;
	inor.resize(n); layor.resize(n);//����Ԫ�ظ�������ʼ�� 
	for(int i=0;i<n;i++){			//�����������в����ӳ�� 
		cin>>inor[i];
		inmp[inor[i]]=i;
	} 
	for(int i=0;i<n;i++){			//����������в����ӳ�� 
		cin>>layor[i];
		laymp[layor[i]]=i;
	} 
	Node *root=creat(0,n-1);		//���� 
	preorder(root);					//�����������֤���Ľṹ 
	return 0;
} 
