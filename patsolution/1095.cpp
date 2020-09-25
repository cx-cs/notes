#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<map> 
#include<cstdio>
using namespace std;
struct node{
    char id[10];
    int time,flag=0;//flag记录进出 
};
bool cmp1(node a,node b){
    if(strcmp(a.id,b.id)!=0)
        return strcmp(a.id,b.id)<0;
    else
        return a.time<b.time;
}
bool cmp2(node a,node b){
    return a.time <b.time;
}
int main(){
    int n,k,maxtime=-1,lastindex=0;
    scanf("%d%d",&n,&k);
    vector<node> record(n),car;
    for(int i=0;i<n;i++){
        char temp[5];
        int h,m,s;
        scanf("%s %d:%d:%d %s",record[i].id,&h,&m,&s,temp);//可以不读掉换行 
        int temptime=h*3600+m*60+s;
        record[i].time=temptime;
        record[i].flag=strcmp(temp,"in")==0?1:-1;//out比in大返回1 
    }
    sort(record.begin(),record.end(),cmp1);//先按名字再按时间排序 
    map<string,int> mapp;
    for(int i=0;i<n-1;i++)
        if(strcmp(record[i].id,record[i+1].id)==0&&record[i].flag==1&&record[i+1].flag==-1){
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id]+=record[i+1].time-record[i].time;//可能多个时间段，多个车牌号
            if(maxtime<mapp[record[i].id])maxtime=mapp[record[i].id];
        }
    sort(car.begin(),car.end(),cmp2);//查询前按时间排序接下来统计 
    vector<int> cnt(n);
    for(int i=0;i<car.size();i++){//利用1和-1统计当前车数目 
        if(i==0)
            cnt[i]+=car[i].flag;
         else
            cnt[i]=cnt[i-1]+car[i].flag;
    }
    for(int i=0;i<k;i++){
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        int temptime=h*3600+m*60+s;
        int j;
        for(j=lastindex;j<car.size();j++){
            if(car[j].time>temptime){//相等时也要计入 
                printf("%d\n",cnt[j-1]);
                break;
            }else if(j==car.size()-1){
                printf("%d\n",cnt[j]);
            }
        }
        lastindex=j;
    }
    for(map<string,int>::iterator it=mapp.begin();it!=mapp.end();it++)
        if(it->second==maxtime)printf("%s ",it->first.c_str());//s.c_str()返回字符数组指针 
    printf("%02d:%02d:%02d",maxtime/3600,(maxtime%3600)/60,maxtime%60);
    return 0;
}
