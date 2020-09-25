#include<cstdio>
using namespace std;
int main(){
    int cnt;
    scanf("%d",&cnt);
    int start[55],end[55],scan[55];
    for(int i=1;i<55;i++){
        scanf("%d",&scan[i]);//换行和空格一样 
        end[i]=i;//end记录最后每个位置存的牌 
    }
    for(int i=0;i<cnt;i++){
        for(int j=1;j<55;j++)
            start[j]=end[j];
        for(int k=1;k<55;k++)
            end[scan[k]]=start[k];//scan是把第k个位置移到scan[k]所以scan[k]这个位置存原来第k个位置的数 
    }
    char c[6]={"SHCDJ"};
    for(int i=1;i<55;i++){
        end[i]=end[i]-1;
        printf("%c%d",c[end[i]/13],end[i]%13+1);//字符与数字关系 
        if(i!=54)printf(" ");
    }
    return 0;
}
