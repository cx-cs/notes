#include<cstdio>
/*int main()//��׼�������
{
    int x;
    while(scanf("%d",&x)==1)//ֹͣҪenter��ctrl+z��enter�����سɹ����������
        printf("%03d\n",x);
    return 0;
}*/

/*#define LOCAL
int main()//�ļ���������ض���
{
    #ifdef LOCAL//������LOCAL�ű���
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int x;
    while(scanf("%d",&x)==1)
        printf("%03d\n",x);
    return 0;
}*/

/*int main()//�ļ��������fopen��
{
    FILE *fin,*fout;
    fin=fopen("input.txt","rb");
    fout=fopen("output.txt","wb");//��Ҫ��׼ioֻ��fin=stdin��fout=stdout
    int x;
    while(fscanf(fin,"%d",&x)==1)
        fprintf(fout,"%3d\n",x);
    fclose(fin);
    fclose(fout);
    return 0;
}*/
