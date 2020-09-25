//��������壺��һ��AVL������Ҷ�ڣ������ҶָNULL������ĺ��Ӻڣ�һ���㵽����Ҷ�ӣ�NULL�������ĺڵ����
//�Ը�ֵ�����
struct node{
    int val;
    node *left,*right;
    node(int d):val(d),left(NULL),right(NULL){};
};
void insert(node* &root,int v){//����Ҫ���� 
    if(root==NULL){
        root=new node(v); 
        return;
    }
    if(abs(root->val)>abs(val))insert(root->left,v);
    else insert(root->right,v);
}
bool judge1(node *root) {//������Ӻ�
    if (root == NULL) return true;
    if (root->val < 0) {
        if (root->left != NULL && root->left->val < 0) return false;
        if (root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}
//��Ϊ�ǵ�NULL�ĺڸ�����������ʵ�ȼ�������������ɫ����ͬ���߶ȣ���max
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