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
    for(i=0;i<n-1&&b[i]<=b[i+1];i++);//�ҳ��м�������˳������һ�������Ժ��Ԫ�غ�ԭ��������ͬ�� 
    for(j=i+1;a[j]==b[j]&&j<n;j++);//�ҵ�һ����ͬ��Ԫ�� 
    if(j==n){//ȫ����ͬ˵���ǲ������� 
        cout<<"Insertion Sort"<<endl;
        sort(a,a+i+2);//a�� a+i+1 
    }else{
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag){
            flag=0;
            for(i=0;i<n;i++){
                if(a[i]!=b[i])//�ŵ�b[i]����һ�� 
                    flag=1;
            }
            k=k*2;
            for(i=0;i<n/k;i++)
                sort(a+i*k,a+(i+1)*k);//��k�� 
            sort(a+n/k*k,a+n);//����ҲҪ�� 
        }
    }
    for(j=0;j<n;j++){
        if(j!=0)cout<<" ";
        cout<<a[j];
    }
    return 0;
}
