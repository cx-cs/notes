#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
int n,k,p,maxFacSum=-1;
vector<int> v,ans,tempAns;
void init(){
	v.push_back(0);
    for(int i=1;i<=n;i++){
    	if(pow(i,p)<=n)v.push_back(pow(i,p));//建表v 
    	else break;
	}
}
void dfs(int index,int tempSum,int tempK,int facSum){
    if(tempK==k){//个数到k个了 
        if(tempSum==n&&facSum>maxFacSum){
                ans=tempAns; 
                maxFacSum=facSum;
        }
        return;
    }
    while(index>=1){
        if(tempSum+v[index]<=n){//满足条件才dfs
			tempAns.push_back(index);
            dfs(index,tempSum+v[index],tempK+1,facSum+index);
			tempAns.pop_back();
        }
        index--;
    }
}
int main(){
    scanf("%d%d%d",&n,&k,&p);
    init(); 
    dfs(v.size()-1,0,0,0);//从最后一个数 
    if(maxFacSum==-1){
        printf("Impossible");
        return 0;
    }
    printf("%d = ",n);
    for(int i=0;i<ans.size();i++){
        if(i!=0)printf(" + ");
        printf("%d^%d",ans[i],p);
    }
    return 0;
}
