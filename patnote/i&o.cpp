#include<cstdio>
/*int main()//标准输入输出
{
    int x;
    while(scanf("%d",&x)==1)//停止要enter，ctrl+z，enter，返回成功读入的项数
        printf("%03d\n",x);
    return 0;
}*/

/*#define LOCAL
int main()//文件输入输出重定向法
{
    #ifdef LOCAL//定义了LOCAL才编译
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int x;
    while(scanf("%d",&x)==1)
        printf("%03d\n",x);
    return 0;
}*/

/*int main()//文件输入输出fopen法
{
    FILE *fin,*fout;
    fin=fopen("input.txt","rb");
    fout=fopen("output.txt","wb");//若要标准io只需fin=stdin，fout=stdout
    int x;
    while(fscanf(fin,"%d",&x)==1)
        fprintf(fout,"%3d\n",x);
    fclose(fin);
    fclose(fout);
    return 0;
}*/
