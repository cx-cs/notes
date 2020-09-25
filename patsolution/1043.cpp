#include<bits/stdc++.h>
using namespace std;
vector<int>post,pre(1005),in;
bool mirror=false;//是否是镜像树
bool yes=true;
void dfs(int root,int start,int end){
 	if(start>end)return;
	if(start==end&&pre[root]!=in[start])yes=false;
	int i;
	if(!mirror){
 		i=start;
 		while(i<end&&pre[root]!=in[i])i++;//找中序的根位置 
	}
	else{
		i=end;
 		while(i>start&&pre[root]!=in[i])i--;//找中序的根位置 
	}
	dfs(root+1,start,i-1);
	dfs(root+1+i-start,i+1,end);
	post.push_back(pre[root]);
}
int main(){
    int N;
    scanf("%d",&N);
	in.resize(N);
    for(int i=0;i<N;++i){
        scanf("%d",&pre[i]);
		in[i]=pre[i];
	}
    if(pre[1]>pre[0])
        mirror=true;
	if(mirror)sort(in.begin(),in.end(),greater<int>());
	else sort(in.begin(),in.end(),less<int>());
    dfs(0,0,N-1);
    if(yes){
        printf("YES\n");
        for(int i=0;i<post.size();++i)
            printf("%s%d",i>0?" ":"",post[i]);
    }else
        printf("NO");
	system("pause");
    return 0;
}