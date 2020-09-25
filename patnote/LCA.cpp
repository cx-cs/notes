struct Node{//�����
	int data,father,level;//���ڵ���pre�е��±�
	Node(int d=0,int f=-1,int l=0):data(d),father(f),level(l){}
};
void createTree(int root,int left,int right,int father,int level){
	if(left>right)
		return;
	int i=left;
	while(i<=right&&in[i]!=pre[root].data)
		++i;
	pre[root]=Node(pre[root].data,father,level);//ȷ����ǰ�����ĸ��ڵ�
	createTree(root+1,left,i-1,root,level+1);
	createTree(root+1+i-left,i+1,right,root,level+1);
}
sort(in,in+n);//�����������
createTree(0,0,n-1,-1,0);//���ڵ�Ϊ-1 
scanf("%d%d",&a,&b);
int ia=n,ib=n;
for(int i=0;i<n;++i){//�ҵ����������pre�����е��±�
	if(pre[i].data==a)
		ia=i;
	if(pre[i].data==b)
		ib=i;
}
if(ia==n&&ib==n){
	printf("ERROR: %d and %d are not found.\n",a,b);
}else if(ia==n){
	printf("ERROR: %d is not found.\n",a);
}else if(ib==n){
	printf("ERROR: %d is not found.\n",b);
}else{
	bool f=true;//true��ʾa����ȸ���ע��a����ia 
	if(pre[ia].level<pre[ib].level){//��iaָ����ȸ���Ľ��
		swap(ia,ib);
		f=false;
	}
	while(pre[ia].level>pre[ib].level)//�����ߵ�����ͬһ���
		ia=pre[ia].father;
	if(ia==ib){
		printf("%d is an ancestor of %d.\n",pre[ia].data,f?a:b);
	}else{
		while(ia!=ib){//ia,ibͬʱ���ϵ�����ֱ������ָ��ͬһ���
			ia=pre[ia].father;
			ib=pre[ib].father;
		}
		printf("LCA of %d and %d is %d.\n",a,b,pre[ia].data);
	}
}