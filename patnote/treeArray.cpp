#include<iostream>
using namespace std;
#define maxn 100
int c[maxn];
int lowbit(int t){//t最右边的1和后面的0化十进制 
return t&(-t);
}

void update(int x,int v){//下标+数值 
    for(int i=x;i<maxn;i+=lowbit(i))//能覆盖c[i]的是c[i+lowbit[i]]
        c[i]+=v;
}
int getsum(int x){//前x个数之和 
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i))//c[i]覆盖lowbit(i)个,sum(1,x)=sum(1,x-lowbit(x))+c[x]
        sum+=c[i];
    return sum;
}

void update(int x,int v){//数值+1 
    for(int i=x;i<maxn;i+=lowbit(i))//能覆盖c[i]的是c[i+lowbit[i]]
        c[i]+=v;
}
int getsum(int x){//小于等于x的数出现次数之和 
    int sum=0;
    for(int i=x;i>=1;i-=lowbit(i))//c[i]覆盖lowbit(i)个,sum(1,x)=sum(1,x-lowbit(x))+c[x]
        sum+=c[i];
    return sum;
} 
//给定正整数序列求每个数左边数之和或者左边小于它的个数边输入边输出，右边的话把数组反过来输入就行。 


//求次数时数太大要映射到1到N且要保持大小顺序。先用结构体存好值和输入顺序下标，按值大小排序
//val 8 6 7 8
//pos 0 1 2 3
//排序后:
//val 6 7 8 8
//pos 1 2 0 3
//A[1]=1,A[2]=2,A[0]=3,A[4]=3（因为和前一个相等)，再输入3123 
//求第k大的数即二分法找get(i)>=k（次数）
