#include<cstdio>
#include<set>//���Ͽ������� 
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
        if(couple[guest[i]]!=-1)//��iλ�ж��� 
            isExist[couple[guest[i]]]=1;//��Ƕ������� 
    }
    set<int> s;
    for(int i=0;i<m;i++)//����û���Ķ����뼯�� 
        if(!isExist[guest[i]])s.insert(guest[i]);
    printf("%d\n",s.size());
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        if(it!=s.begin())printf(" ");
        printf("%05d",*it);
    }
    return 0;
}
