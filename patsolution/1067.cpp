#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,num=0,index=1;
    scanf("%d",&N);
    vector<int> position(N);//�±��ʾ����i������Ԫ�ر�ʾi�ڵڼ�λ
    for(int i=0;i<N;++i){
        int a;
        scanf("%d",&a);
        position[a]=i;
    }
    while(index<N){
        while(position[0]!=0){//0����0��λ,���ֱ�ʾ�������0��λ��
            swap(position[0],position[position[0]]);
            ++num;
        }
        for(;index<N;++index)//0��0��λ����indexλ��ʼ���������в��ڱ�λ����
            if(position[index]!=index){
                swap(position[0],position[index]);
                ++num;
                break;
            }
    }
    printf("%d",num);
    return 0;
}