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
    part[0]=n/100000000;//�ڵĲ��� 
    part[1]=(n%100000000)/10000;//��Ĳ��� 
    part[2]=n%10000;//����10000�Ĳ��� 
    bool zero=false;
    int first=0;
    for(int i=0;i<3;i++){
    	if(part[i]==0)continue; 
        for(int j=3;j>=0;j--){//ÿ����4λ 
            int cur=(part[i]/J[j])%10;
            if(cur!=0){//��ǰ����0 
                if(zero){//ǰ����0 
                    first++==0?cout<<"ling":cout<<" ling";
                    zero=false;
                }
                if(j==0)//��λ�� 
                    first++==0?cout<<num[cur]:cout<<' '<<num[cur];
                else                             
                    first++==0?cout<<num[cur]<<' '<<c[j]:cout<<' '<<num[cur]<<' '<<c[j];
            }else{//��ǰ��=0 
                if(j!=0&&first)zero=true;//���0���ڸ�λ����ǰ���з������ 
            }
        }
        if(i<2)cout<<' '<<c[i+4];
    }
}
