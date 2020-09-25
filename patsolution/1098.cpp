#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
void downAdjust(vector<int> &b,int low,int high){
    int i=1,j=i*2;
    while(j<=high){
        if(j+1<=high&&b[j]<b[j+1])j=j+1;//ȡ���ҽ����һ�� 
        if(b[i]>=b[j])break;//����֮ǰ�Ѿ�����������һ��������������������ҽ�����Ȼ���ں������� 
        swap(b[i],b[j]);//����ӵ�һ����Ҷ�ӽ��������� 
        i=j;j=i*2;//�������� 
    }
}
int main(){
    int n,p=2;
    scanf("%d",&n);
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    while(p<=n&&b[p-1]<=b[p])p++;
    int index=p;
    while(p<=n&&a[p]==b[p])p++;
    if(p==n+1){
        printf("Insertion Sort\n");
        sort(b.begin()+1,b.begin()+index+1);
    }else{//�����򣬴󶥶�ÿ�ΰѶ��ŵ���󹹳�С���� 
        printf("Heap Sort\n");
        p=n;//������һ�˶����ǰѶ��ŵ���Ӧλ�ò������� 
        while(p>2&&b[p]>=b[1])p--;
        swap(b[1],b[p]);
        downAdjust(b,1,p-1);//1��p-1�������ɴ󶥶�
    }
    printf("%d",b[1]);
    for(int i=2;i<=n;i++)
        printf(" %d",b[i]);
    return 0;
}
