//bst第一个相同值是根但反bst最后一个相同值才是根
//前序中序转后序：
void dfs(int root,int start,int end){
 	if(start>end)return;
 	int i=start;
 	while(i<end&&pre[root]!=in[i])i++;//找中序的根位置，如果是反bst从i=end开始找
 	dfs(root+1,start,i-1);//想建树的话是new root=data;root->left=dfs;right=dfs;return root;
 	dfs(root+1+i-start,i+1,end);
	ans.push_back(pre[root]);
}
//后序中序转前序：
void dfs(int root,int start,int end){
 	if(start>end)return;
 	int i=start;
 	while(i<end&&post[root]!=in[i])i++;
 	ans.push_back(post[root]);
	dfs(root-1-end+i,start,i-1);
 	dfs(root-1,i+1,end);
}
//后序中序转层序，最后要对ans排序
void dfs(int root, int start, int end, int index) {//level的话每次加1
    if (start > end) return;
    int i = start;
    while (i < end && in[i] != post[root]) i++;
    ans.push_back({index, post[root]});
    dfs(root - 1 - end + i, start, i - 1, 2 * index + 1);
    dfs(root - 1, i + 1, end, 2 * index + 2);
}
//先序后序转中序(可能不唯一)
//查找得到的先根序列中根节点的下一结点在后根序列中的位置正好等于right-1则不唯一，因为这说明只有一个孩子不知道左右
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