//bst��һ����ֵͬ�Ǹ�����bst���һ����ֵͬ���Ǹ�
//ǰ������ת����
void dfs(int root,int start,int end){
 	if(start>end)return;
 	int i=start;
 	while(i<end&&pre[root]!=in[i])i++;//������ĸ�λ�ã�����Ƿ�bst��i=end��ʼ��
 	dfs(root+1,start,i-1);//�뽨���Ļ���new root=data;root->left=dfs;right=dfs;return root;
 	dfs(root+1+i-start,i+1,end);
	ans.push_back(pre[root]);
}
//��������תǰ��
void dfs(int root,int start,int end){
 	if(start>end)return;
 	int i=start;
 	while(i<end&&post[root]!=in[i])i++;
 	ans.push_back(post[root]);
	dfs(root-1-end+i,start,i-1);
 	dfs(root-1,i+1,end);
}
//��������ת�������Ҫ��ans����
void dfs(int root, int start, int end, int index) {//level�Ļ�ÿ�μ�1
    if (start > end) return;
    int i = start;
    while (i < end && in[i] != post[root]) i++;
    ans.push_back({index, post[root]});
    dfs(root - 1 - end + i, start, i - 1, 2 * index + 1);
    dfs(root - 1, i + 1, end, 2 * index + 2);
}
//�������ת����(���ܲ�Ψһ)
//���ҵõ����ȸ������и��ڵ����һ����ں�������е�λ�����õ���right-1��Ψһ����Ϊ��˵��ֻ��һ�����Ӳ�֪������
void inOrder(int root,int left,int right){
    if(left>=right){
        if(left==right)//left==right��ֻ��һ�����
            in.push_back(pre[root]);//ѹ���и�������
        return;
    }
    int i=left;
    while(i<right&&post[i]!=pre[root+1])//�����ȸ������и��ڵ����һ����ں�������е�λ��
        ++i;
    if(i==right-1)
        unique=false;//������̬��Ψһ
    inOrder(root+1,left,i);//i��ʵ�����
    in.push_back(pre[root]);
    inOrder(root+i-left+2,i+1,right-1);//������
}