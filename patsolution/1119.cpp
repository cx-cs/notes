#include<cstdio>
#include<vector>
using namespace std;
vector<int> in,pre,post;
//���ҵõ����ȸ������и��ڵ����һ����ں�������е�λ�����õ���right-1��Ψһ����Ϊ��˵��ֻ��һ�����Ӳ�֪������
bool unique=true;
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
int main(){
	int n;
	scanf("%d",&n);
	pre.resize(n),post.resize(n);
	for(int i=0;i<n;i++) 
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&post[i]);
	inOrder(0,0,n-1);
	printf("%s\n%d",unique==true?"Yes":"No",in[0]);
	for(int i=1;i<in.size();i++)
		printf(" %d",in[i]);
	printf("\n");
	return 0;
}
