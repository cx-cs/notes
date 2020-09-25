#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int N, M, K, Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    queue<int> in_line[22], out_line;
    vector<int> time(N, 8 * 60), end_time(K + 1), p_time(K + 1), begin_time(K + 1);
    for( int i = 1; i <= K; ++i )
    {
        scanf("%d", &p_time[i]);
        if( in_line[ (i - 1) % N ].size() < M )
            in_line[ (i - 1) % N ].push(i);
        else out_line.push(i);
    }
    for( int i = 0, min; i < K; ++i )
    {
        for( min = 0; in_line[min].empty(); ++min );//min是第一个非空的
        for( int j = 0; j < N; ++j )
            if( !in_line[j].empty() && time[j] + p_time[ in_line[j].front() ] < time[min] + p_time[ in_line[min].front() ] )
                min = j;//找出队最早的
        begin_time[ in_line[min].front() ] = time[min];
        end_time[ in_line[min].front() ] = time[min] = time[min] + p_time[ in_line[ min ].front() ];
        in_line[min].pop();
        if( !out_line.empty() )
        {
            in_line[min].push( out_line.front() );
            out_line.pop();
        }
    }
    for( int i = 0, c; i < Q; ++i )
    {
        scanf("%d", &c);
        if( begin_time[c] < 17 * 60 )
            printf("%02d:%02d\n", end_time[c] / 60, end_time[c] % 60);
        else printf("Sorry\n");
    }
	system("pause");
}

