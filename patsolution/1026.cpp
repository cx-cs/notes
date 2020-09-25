#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*���Ŷ�״̬���ˣ�������ң�ѡ��
	��ͨ�ͻ���
		˳��ѡȡ���������׸���������
	VIP�ͻ���
		˳��ѡȡ���������׸�VIP����������ѡ�����������׸���ͨ����������

�Ŷ�״̬�����������������ѡ��
	���������Ϊ��ͨ����
		�����׸��˿ͣ�
	���������ΪVIP����
		�����׸�VIP�˿ͣ�����VIP�˿��Ŷ����������׹˿ͣ�*/
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
        rec[i].p_time = min( p * 60, 120 * 60 );//����ʱ�䲻����2Сʱ
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
        //�������ҵ���һ��������
        if( time[min] <= rec[0].a_time )//�����������Ŷ�
        {
            cust = 0;
            if(rec[cust].tag){//�����vip������û��vip��
                for(  table = 0; table < K; ++table )
                    if( isvip[table] && time[table] <= rec[cust].a_time )
                        break;
            }
            else table=min;//����vip�͵�ǰ���
            if(table==K)table=min;//��vip���Ҳ���vip��Ҳ��ǰ���
        }
        else//Ҫ�Ŷ�
        {
            table = min;
            if(isvip[table]){//��vip���Ļ�����vip�ͻ�
                for( cust = 0; cust < rec.size(); ++cust )
                    if( rec[cust].tag && rec[cust].a_time <= time[min] )
                        break;
            }
            else cust=0;//����vip���͵�ǰ����
            if(cust == rec.size() )cust = 0;//û��vip�͵�ǰ����
        }
        rec[cust].s_time = max( rec[cust].a_time, time[table] );
        rec[cust].w_time = rec[cust].s_time - rec[cust].a_time;
        time[table] = rec[cust].s_time + rec[cust].p_time;
        if( rec[cust].s_time < 21 * 3600 )
        {
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", rec[cust].a_time / 3600, ( rec[cust].a_time / 60 ) % 60, rec[cust].a_time % 60, rec[cust].s_time / 3600, ( rec[cust].s_time / 60 ) % 60, rec[cust].s_time % 60, ( rec[cust].w_time + 30 ) / 60);
            ++sum[table];
        }
        rec.erase( rec.begin() + cust );//ɾ��

    }
    for( int i = 0; i < K; ++i )
        printf("%s%d", i ? " ":"", sum[i]);
}

