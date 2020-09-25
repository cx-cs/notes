#include <cstdio>
#include <vector>
#include <unordered_map>//快 
using namespace std;
vector<vector<int> > v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;//前面的 
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
	tempPath.push_back(node);
    if (node == end1){
		if(cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer)){
			minCnt = cnt;
			minTransfer = transferCnt(tempPath);
			path = tempPath;
		}
    }
    visit[node]=1;
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            dfs(v[node][i], cnt + 1);
        }
    }
    visit[node]=0;
	tempPath.pop_back();
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);//二维 
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;//线路号，相当于line[pre][temp] 
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        dfs(start, 0);
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {//前后不同输出前，前后同不输出，所以最后一段 
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
	system("pause");
    return 0;
}
