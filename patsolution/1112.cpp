#include<iostream>
using namespace std;
int main(){
    string input,output="";
    int K;
    cin>>K>>input;
    int hashTable[128]={0};//��ʾ�ǲ��ǻ���
    for(int i=0;i<input.size();){
        int j=i+1;
        while(j<input.size()&&input[j]==input[i])//�ҵ�iλ�ú��һ��������input[i]���ַ�λ��
            ++j;
        if(hashTable[input[i]]>=0)//��ǰ��input[i]�����ǻ�������û���ֹ� 
            hashTable[input[i]]=(j-i)%K==0?1:-1;
        i=j;
    }
    bool out[128]={false};//��ʾ�ַ��Ƿ��ѱ������
    for(int i=0;i<input.size();){
        output+=input[i];//����ǰ�ַ�������ȷ���ַ�����
        if(hashTable[input[i]]>0){//�ǻ���
            if(!out[input[i]]){
                cout<<input[i];
                out[input[i]]=true;//�˻����ѱ������
            }
            i+=K;//ÿK����������ȷ���ַ�����ֻ���1��
        }
        else if(hashTable[input[i]]<0)//���ǻ���
            i++;
    }
    cout<<endl<<output;//�����ȷ���ַ���
    return 0;
}
