#include<bits/stdc++.h>
using namespace std;
struct Station{//����վ�ṹ��
    double dis;
    double price;
};
bool cmp(const Station&s1,const Station&s2){//�ȽϺ���
    return s1.dis!=s2.dis?s1.dis<s2.dis:s1.price<s2.price;
}
int main(){
    double Cmax,D,Davg;
    int N;
    scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
    vector<Station> station(N+1);//����N+1����վ
    for(int i=0;i<N;++i)//��ȡ����
        scanf("%lf%lf",&station[i].price,&station[i].dis);
    station[N].dis=D;//�����һ������վ���붨ΪD���ͼ���Ϊ0����Ϊ�յ�
    station[N].price=0;
    sort(station.begin(),station.end()-1,cmp);//ֻ��ǰN����վ���������򼴿�
    double farestDis=Cmax*Davg;//��������Զ�ܵ���ľ���
    double sumPrice=0.0,currentTank=0.0;//�ܻ��ѣ���ǰ�����еĴ���
    if(station[0].dis!=0.0){//����ھ���Ϊ0��û�м���վ�����ܳ�����ֱ�����
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    int currentIndex=0;//��ǰ����վ���
    while(currentIndex<N){//���û�е����յ㣬����ѭ��
        int minIndex=-1;//��һ��Ӧǰ���ļ���վ
        double minPrice=1e6*1.0;
        //Ѱ�Ҿ���������ͼ۵���currentIndex����վminIndex������Ҳ����������ܵ���ļ���վ��Ѱ���ͼ���͵ļ���վminIndex
        for(int i=currentIndex+1;i<=N&&station[i].dis<=station[currentIndex].dis+farestDis;++i){
            if(minPrice>=station[i].price){
                minIndex=i;
                minPrice=station[i].price;
            }
            if(station[i].price<station[currentIndex].price)//ֻҪ��һ���͵����̻�
                break;
        }
        if(minIndex==-1){ //������ﲻ���κμ���վ�������Զ�ܵ���ľ���
            double maxDis=station[currentIndex].dis+farestDis;
            printf("The maximum travel distance = %.2f",maxDis);
            return 0;
        }
        
        double tempTank=(station[minIndex].dis-station[currentIndex].dis)/Davg;//����minIndex����վ��Ҫʹ�õ�����
        if(station[minIndex].price<station[currentIndex].price){//minIndex����վ�ͼ۵��ڵ�ǰ����վ
            sumPrice+=station[currentIndex].price*(tempTank-currentTank);//ֻ��ӵ��ܵ���minIndex����
            currentTank=0;//����minIndex����վ����Ϊ0
        }else{//minIndex����վ�ͼ۲����ڵ�ǰ����վ
            sumPrice+=station[currentIndex].price*(Cmax-currentTank);//�ڵ�ǰ����վ������
            currentTank=Cmax-tempTank;//����minIndex����վ����ΪCmax-tempTank
        }
        currentIndex=minIndex;//ǰ��minIndex����վ
    }
    printf("%.2f",sumPrice);
    return 0;
}