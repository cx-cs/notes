#include<bits/stdc++.h>
using namespace std;
int data[100005],Next[100005];
int main(){
    int begin,N,K;
    scanf("%d%d%d",&begin,&N,&K);
    for(int i=0;i<N;++i){//��ȡ����
        int address;
        scanf("%d",&address);
        scanf("%d%d",&data[address],&Next[address]);
    }
    vector<int>listAddress;//�����������ַ
    while(begin!=-1){
        listAddress.push_back(begin);
        begin=Next[begin];
    }
    for(int i=K;i<=listAddress.size();i+=K)//���з�ת
        reverse(listAddress.begin()+i-K,listAddress.begin()+i);
    for(int i=0;i<listAddress.size()-1;++i)//���
        printf("%05d %d %05d\n",listAddress[i],data[listAddress[i]],listAddress[i+1]);
    printf("%05d %d -1\n",listAddress.back(),data[listAddress.back()]);
	system("pause");
    return 0;
}