#include<cstdio>
#include<set>//集合可以升序 
#include<vector>
using namespace std;
int main(){
    int n,a,b,m;
    scanf("%d",&n);
    vector<int> couple(100000,-1);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        couple[a]=b;
        couple[b]=a;
    }
    scanf("%d",&m);
    vector<int> guest(m),isExist(100000);
    for(int i=0;i<m;i++){
        scanf("%d",&guest[i]);
        if(couple[guest[i]]!=-1)//第i位有对象 
            isExist[couple[guest[i]]]=1;//标记对象来了 
    }
    set<int> s;
    for(int i=0;i<m;i++)//对象没来的都加入集合 
        if(!isExist[guest[i]])s.insert(guest[i]);
    printf("%d\n",s.size());
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        if(it!=s.begin())printf(" ");
        printf("%05d",*it);
    }
    return 0;
}
