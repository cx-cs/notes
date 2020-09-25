#include <iostream>
using namespace std;
struct node {
    string data;
    int left, right;
}tree[100];
bool isLeaf(int v){//判断是否是叶子结点
    return tree[v].left==-1&&tree[v].right==-1;
}
//如果左子树或者右子树（如果存在的话）不是叶子结点，就需要()将左子树或者右子树包含进去
void DFS(int v){//深度优先遍历
    if(tree[v].left!=-1){//左子树非空
        cout<<(!isLeaf(tree[v].left)?"(":"");//如果左子树不是叶子结点输出(
        DFS(tree[v].left);
        cout<<(!isLeaf(tree[v].left)?")":"");//如果左子树不是叶子结点输出)
    }
    cout<<tree[v].data;
    if(tree[v].right!=-1){//右子树非空
        cout<<(!isLeaf(tree[v].right)?"(":"");//如果右子树不是叶子结点输出(
        DFS(tree[v].right);
        cout<<(!isLeaf(tree[v].right)?")":"");//如果右子树不是叶子结点输出)
    }
}
int main() {
    int have[100] = {0}, n, root = 1;
    cin >> n;
    for(int i  = 1; i <= n; i++) {
        cin >> tree[i].data >> tree[i].left >> tree[i].right;
        if(tree[i].left != -1) have[tree[i].left] = 1;//haveparent 
        if(tree[i].right != -1) have[tree[i].right] = 1;
    }
    while(have[root] == 1) root++;//无根为根 
    DFS(root);
    return 0;
}
