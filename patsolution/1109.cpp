#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    string name;
    int height;
};
int cmp(node a, node b) {
    return a.height!=b.height?a.height>b.height:a.name<b.name;
}
int main(){
    int n,k,m;
    cin>>n>>k;
    vector<node> stu(n);
    for(int i=0;i<n;i++){
        cin>>stu[i].name;
        cin>>stu[i].height;
    }
    sort(stu.begin(),stu.end(),cmp);
    int t=0,row=k;
    while(row){ 
        if(row==k){
            m=n-n/k*(k-1);//每行人数 
        }else{
            m=n/k;
        }
        vector<string> ans(m);
        ans[m/2]=stu[t].name;//直接放最高的，因为是按名字排好了序 
        int j=m/2-1;//因为从左开始，先放完左边 
        for(int i=t+1;i<t+m;i=i+2)//i范围当然是t+1到t+m-1只有m-1个因为最高的已经放了 
            ans[j--]=stu[i].name;
        j=m/2+1;
        for(int i=t+2;i<t+m;i=i+2)//i范围t+2到t+m-2 
            ans[j++]=stu[i].name;
        cout<<ans[0];
        for(int i=1;i<m;i++)
            cout<<" "<<ans[i];
        cout<<endl;
        t=t+m;
        row--;
    }
    return 0;
}
