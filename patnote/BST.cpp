struct node{
    int v;
    node *left,*right;
    node(int d):v(d),left(NULL),right(NULL){};
};
void insert(node* &root,int v){//必须要引用 
    if(root==NULL){
        root=new node(v); 
        return;
    }
    if(v<=root->v)insert(root->left,v);
    else insert(root->right,v);
}
	node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        insert(root,t);
	}