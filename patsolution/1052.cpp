#include<bits/stdc++.h>
using namespace std;
int data[(int)(1e5+5)],Next[(int)(1e5+5)];
bool cmp(int a,int b){//�ȽϺ���
    return data[a]<data[b];
}
int main(){
    int N,first;
    scanf("%d%d",&N,&first);
    if(first==-1){//Ϊ������ʱֱ�����0 -1
        printf("0 -1\n");
        return 0;
    }
    for(int i=0;i<N;++i){//��ȡ����  
        int a;
        scanf("%d",&a);
        scanf("%d%d",&data[a],&Next[a]);
    }
    vector<int>listAddress;//�����������ַ 
    while(first!=-1){
        listAddress.push_back(first);
        first=Next[first];
    }
    sort(listAddress.begin(),listAddress.end(),cmp);//��data��С��������
    printf("%d %05d\n",listAddress.size(),listAddress.front());
    for(int i=0;i<listAddress.size()-1;++i)
        printf("%05d %d %05d\n",listAddress[i],data[listAddress[i]],listAddress[i+1]);
    printf("%05d %d -1",listAddress.back(),data[listAddress.back()]);
    return 0;
}