#include <cstdio>
#include<algorithm> 
using namespace std;
struct node {
    int val;
    node *left, *right;
	node(int value):val(value),left(NULL),right(NULL) {};
};
//找最近的不平衡结点，若插入点在它的右子树的右子树(RR)则左旋(根下中间上)
node *rotateLeft(node *root) {//
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
//插入点在它的左子树的左子树(LL)则右旋(根下中间上)
node *rotateRight(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
//插入点在它的左子树的右子树(LR)则先左旋中间再右旋根
node *rotateLeftRight(node *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}
//插入点在它的右子树的左子树(RL)则先右旋中间再左旋根
node *rotateRightLeft(node *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}
int getHeight(node *root) {
    if(root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node(val);
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    } else {
        root->right = insert(root->right, val);
        if(getHeight(root->left) - getHeight(root->right) == -2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}
int main() {
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->val);
	system("pause");
    return 0;
}