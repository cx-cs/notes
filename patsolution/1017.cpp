#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct
{
    int a_time, p_time;
}record;
int main()
{
    int N, K, cnt = 0, sum = 0;
    scanf("%d %d", &N, &K);
    vector<int> time( K, 8 * 60 * 60 );
    vector<record> rec;
    for( int i = 0, h, m, s, p; i < N; ++i )
    {
        scanf("%d:%d:%d %d", &h, &m, &s, &p);
        if( h * 3600 + m * 60 + s <= 17 * 3600 )
            rec.push_back( { h * 3600 + m * 60 + s, p * 60 } );
    }
    sort( rec.begin(), rec.end(), [] ( record a, record b ) { return a.a_time < b.a_time; } );
    for( int i = 0, min; i < rec.size(); ++i )
    {
        min = 0;
        for( int j = 0; j < K; ++j )
            if( time[j] < time[min] )
                min = j;
        if( time[min] > rec[i].a_time )
        {
            sum += time[min] - rec[i].a_time;
            time[min] += rec[i].p_time;
        }
        else time[min] = rec[i].p_time + rec[i].a_time;
    }
    printf("%.1f", sum / 60.0 / rec.size() );
}

