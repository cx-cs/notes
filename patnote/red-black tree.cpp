//红黑树定义：是一种AVL，根和叶黑（这里的叶指NULL，红根的孩子黑，一个点到所有叶子（NULL）包含的黑点相等
//以负值代替红
struct node{
    int val;
    node *left,*right;
    node(int d):val(d),left(NULL),right(NULL){};
};
void insert(node* &root,int v){//必须要引用 
    if(root==NULL){
        root=new node(v); 
        return;
    }
    if(abs(root->val)>abs(val))insert(root->left,v);
    else insert(root->right,v);
}
bool judge1(node *root) {//红根孩子黑
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
//因为是到NULL的黑个数，所以其实等价于左右子树黑色数相同，高度，即max
int getNum(node *root) {
    if (root == NULL) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(node *root) {
    if (root == NULL) return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}