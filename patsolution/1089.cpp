#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,a[100],b[100],i,j;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n-1&&b[i]<=b[i+1];i++);//找出中间序列有顺序的最后一个，这以后的元素和原序列是相同的 
    for(j=i+1;a[j]==b[j]&&j<n;j++);//找第一个不同的元素 
    if(j==n){//全部相同说明是插入排序 
        cout<<"Insertion Sort"<<endl;
        sort(a,a+i+2);//a到 a+i+1 
    }else{
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag){
            flag=0;
            for(i=0;i<n;i++){
                if(a[i]!=b[i])//排到b[i]的下一步 
                    flag=1;
            }
            k=k*2;
            for(i=0;i<n/k;i++)
                sort(a+i*k,a+(i+1)*k);//排k个 
            sort(a+n/k*k,a+n);//后面也要排 
        }
    }
    for(j=0;j<n;j++){
        if(j!=0)cout<<" ";
        cout<<a[j];
    }
    return 0;
}
