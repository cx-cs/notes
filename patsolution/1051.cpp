#include<cstdio>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<k;i++){
        stack<int> s;
        vector<int> v(n+1);
        for(int j=1;j<=n;j++)
            scanf("%d",&v[j]);
        int current=1;
        for(int j=1;j<=n;j++){
            s.push(j);//����ջ 
            if(s.size()>m)break;//�������� 
            while(!s.empty()&&s.top()==v[current]){
                s.pop();
                current++;
            }
        }
        if(current==n+1)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
