#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*非排队状态：人（队首玩家）选桌
	普通客户：
		顺序选取桌号升序首个开放桌；
	VIP客户：
		顺序选取桌号升序首个VIP桌（若无则选区桌号升序首个普通开放桌）；

排队状态：桌（最早可用桌）选人
	最早可用桌为普通桌：
		分配首个顾客；
	最早可用桌为VIP桌：
		分配首个VIP顾客（若无VIP顾客排队则分配给队首顾客）*/
struct item
{
    int a_time, p_time, s_time, w_time, tag;
};
int main()
{
    int N, M, K;
    scanf("%d", &N);
    vector<item> rec(N);
    for( int i = 0, h, m, s, p; i < N; ++i )
    {
        scanf("%d:%d:%d %d %d", &h, &m, &s, &p, &rec[i].tag);
        rec[i].a_time = h * 3600 + m * 60 + s;
        rec[i].p_time = min( p * 60, 120 * 60 );//处理时间不超过2小时
    }
    sort( rec.begin(), rec.end(), [] ( item a, item b ) { return a.a_time < b.a_time; } );
    scanf("%d %d", &K, &M);
    vector<int> time(K, 8 * 3600), isvip(K, 0), sum(K, 0);
    for( int i = 0, n; i < M; ++i )
    {
        scanf("%d", &n);
        isvip[n - 1] = 1;
    }
    while( !rec.empty() )
    {
        int min = 0, table, cust;
        for( int i = 0; i < K; ++i )
            if( time[i] < time[min] )
                min = i;
        //以上是找到第一个可用桌
        if( time[min] <= rec[0].a_time )//人来的晚不用排队
        {
            cust = 0;
            if(rec[cust].tag){//如果是vip就找有没有vip桌
                for(  table = 0; table < K; ++table )
                    if( isvip[table] && time[table] <= rec[cust].a_time )
                        break;
            }
            else table=min;//不是vip就当前这个
            if(table==K)table=min;//是vip但找不到vip桌也当前这个
        }
        else//要排队
        {
            table = min;
            if(isvip[table]){//是vip桌的话就找vip客户
                for( cust = 0; cust < rec.size(); ++cust )
                    if( rec[cust].tag && rec[cust].a_time <= time[min] )
                        break;
            }
            else cust=0;//不是vip桌就当前这人
            if(cust == rec.size() )cust = 0;//没有vip就当前这人
        }
        rec[cust].s_time = max( rec[cust].a_time, time[table] );
        rec[cust].w_time = rec[cust].s_time - rec[cust].a_time;
        time[table] = rec[cust].s_time + rec[cust].p_time;
        if( rec[cust].s_time < 21 * 3600 )
        {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", rec[cust].a_time / 3600, ( rec[cust].a_time / 60 ) % 60, rec[cust].a_time % 60, rec[cust].s_time / 3600, ( rec[cust].s_time / 60 ) % 60, rec[cust].s_time % 60, ( rec[cust].w_time + 30 ) / 60);
            ++sum[table];
        }
        rec.erase( rec.begin() + cust );//删掉

    }
    for( int i = 0; i < K; ++i )
        printf("%s%d", i ? " ":"", sum[i]);
}

