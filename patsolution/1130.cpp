#include <iostream>
using namespace std;
struct node {
    string data;
    int left, right;
}tree[100];
bool isLeaf(int v){//�ж��Ƿ���Ҷ�ӽ��
    return tree[v].left==-1&&tree[v].right==-1;
}
//���������������������������ڵĻ�������Ҷ�ӽ�㣬����Ҫ()������������������������ȥ
void DFS(int v){//������ȱ���
    if(tree[v].left!=-1){//�������ǿ�
        cout<<(!isLeaf(tree[v].left)?"(":"");//�������������Ҷ�ӽ�����(
        DFS(tree[v].left);
        cout<<(!isLeaf(tree[v].left)?")":"");//�������������Ҷ�ӽ�����)
    }
    cout<<tree[v].data;
    if(tree[v].right!=-1){//�������ǿ�
        cout<<(!isLeaf(tree[v].right)?"(":"");//�������������Ҷ�ӽ�����(
        DFS(tree[v].right);
        cout<<(!isLeaf(tree[v].right)?")":"");//�������������Ҷ�ӽ�����)
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
    while(have[root] == 1) root++;//�޸�Ϊ�� 
    DFS(root);
    return 0;
}
