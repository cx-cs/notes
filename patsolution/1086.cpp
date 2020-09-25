#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
vector<int> pre,in,post,value;
void postorder(int root,int start,int end){
    if(start>end)return;
    int i=start;
    while(i<end&&in[i]!=pre[root])i++;//i�������λ�� 
    postorder(root+1,start,i-1);//��������������ǰ���е��±���ǰ���+1 
    postorder(root+1+i-start,i+1,end);//��������������ǰ���е��±���ǰ�����������������+2 
    post.push_back(pre[root]);//����Ǹ� 
}
int main(){
    int n;
    scanf("%d",&n);
    char str[5];
    stack<int> s;
    int key=0;
    while(~scanf("%s",str)){
        if(strlen(str)==4){
            int num;
            scanf("%d",&num);
            value.push_back(num);
            pre.push_back(key);//ǰ�� 
            s.push(key++);
        }else{
            in.push_back(s.top());//���� 
            s.pop();
        }
    }
    postorder(0,0,n-1);//��ǰ����������� 
    printf("%d",value[post[0]]);
    for(int i=1;i<n;i++)
        printf(" %d",value[post[i]]);
    return 0;
}
