#include<cstdio>
using namespace std;
int main(){
    int cnt;
    scanf("%d",&cnt);
    int start[55],end[55],scan[55];
    for(int i=1;i<55;i++){
        scanf("%d",&scan[i]);//���кͿո�һ�� 
        end[i]=i;//end��¼���ÿ��λ�ô���� 
    }
    for(int i=0;i<cnt;i++){
        for(int j=1;j<55;j++)
            start[j]=end[j];
        for(int k=1;k<55;k++)
            end[scan[k]]=start[k];//scan�ǰѵ�k��λ���Ƶ�scan[k]����scan[k]���λ�ô�ԭ����k��λ�õ��� 
    }
    char c[6]={"SHCDJ"};
    for(int i=1;i<55;i++){
        end[i]=end[i]-1;
        printf("%c%d",c[end[i]/13],end[i]%13+1);//�ַ������ֹ�ϵ 
        if(i!=54)printf(" ");
    }
    return 0;
}
