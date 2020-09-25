#include<cstdio>
#include<vector>
using namespace std;
vector<int> sum,resultArr;
int n,m;
void Func(int i,int &j,int &tempsum){//不二分超时 
    int left=i,right=n;
    while(left<right){
        int mid=(left+right)/2;
        if(sum[mid]-sum[i-1]>=m)//计算i到mid的和 
            right=mid;//不能减1 
        else
            left=mid+1;
    }
    j=right;
    tempsum=sum[j]-sum[i-1];
}
int main() {
    scanf("%d%d",&n,&m);
    sum.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];//一开始就算出和 
    }
    int minans=sum[n];
    for(int i=1;i<=n;i++){//每次计算i到n 
        int j,tempsum;
        Func(i,j,tempsum);
        if(tempsum>=m&&tempsum<=minans){
            if(tempsum<minans){
                resultArr.clear();
                minans=tempsum;
            }
            resultArr.push_back(i);
           	resultArr.push_back(j);
        }
    }
    for(int i=0;i<resultArr.size();i+=2)//偶数个 
        printf("%d-%d\n",resultArr[i],resultArr[i+1]);
    return 0;
}
