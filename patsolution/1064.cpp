//由bst中序和完全二叉树构造前序 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> in;
vector<int> tree;
int n;
int index=1;
void inOrder(int root){//这里是对完全二叉树进行中序遍历然后填入数值 
	if(root>n)return;
	inOrder(root*2);
	tree[root]=in[index++];
	inOrder(root*2+1);
	return;
}
int main(){
	cin>>n;
	in.resize(n+1),tree.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>in[i];
	sort(in.begin(),in.end());
	inOrder(1);
	for (int i=1;i<=n;i++){
		if (i!=1)cout<<" ";
		cout<<tree[i];
	}
	return 0;
}
