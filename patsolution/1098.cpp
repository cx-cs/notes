#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void downAdjust(vector<int> &b,int low,int high){
    int i=1,j=i*2;
    while(j<=high){
        if(j+1<=high&&b[j]<b[j+1])j=j+1;//取左右结点大的一个 
        if(b[i]>=b[j])break;//由于之前已经调整过至少一次所以如果根还大于左右结点则必然大于后面所有 
        swap(b[i],b[j]);//这里从第一个非叶子结点调整即可 
        i=j;j=i*2;//接着往下 
    }
}
int main(){
    int n,p=2;
    scanf("%d",&n);
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    while(p<=n&&b[p-1]<=b[p])p++;
    int index=p;
    while(p<=n&&a[p]==b[p])p++;
    if(p==n+1){
        printf("Insertion Sort\n");
        sort(b.begin()+1,b.begin()+index+1);
    }else{//堆排序，大顶堆每次把顶放到最后构成小到大 
        printf("Heap Sort\n");
        p=n;//堆排序一趟定义是把顶放到相应位置并调整堆 
        while(p>2&&b[p]>=b[1])p--;
        swap(b[1],b[p]);
        downAdjust(b,1,p-1);//1到p-1调整生成大顶堆
    }
    printf("%d",b[1]);
    for(int i=2;i<=n;i++)
        printf(" %d",b[i]);
    return 0;
}
