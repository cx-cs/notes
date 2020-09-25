#include<iostream>
#include<string>
using namespace std;
string num[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string c[6]={"","Shi","Bai","Qian","Yi","Wan"};
int J[]={1,10,100,1000};
int main(){
    int n;
    cin>>n;
    if (n==0){
        cout<<"ling";
        return 0;
    }
    if(n<0){
        cout<<"Fu ";
        n=-n;
    }
    int part[3];
    part[0]=n/100000000;//亿的部分 
    part[1]=(n%100000000)/10000;//万的部分 
    part[2]=n%10000;//少于10000的部分 
    bool zero=false;
    int first=0;
    for(int i=0;i<3;i++){
    	if(part[i]==0)continue; 
        for(int j=3;j>=0;j--){//每部分4位 
            int cur=(part[i]/J[j])%10;
            if(cur!=0){//当前数非0 
                if(zero){//前面有0 
                    first++==0?cout<<"ling":cout<<" ling";
                    zero=false;
                }
                if(j==0)//个位数 
                    first++==0?cout<<num[cur]:cout<<' '<<num[cur];
                else                             
                    first++==0?cout<<num[cur]<<' '<<c[j]:cout<<' '<<num[cur]<<' '<<c[j];
            }else{//当前数=0 
                if(j!=0&&first)zero=true;//这个0不在各位而且前面有非零的数 
            }
        }
        if(i<2)cout<<' '<<c[i+4];
    }
}
