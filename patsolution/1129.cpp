#include <cstdio>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    bool operator < (const node a)  const{//重载 
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;//结构体集合 
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;//集合计数 
            for(set<node>::iterator it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);//it是结构体指针 
                tempCnt++;
            }
            printf("\n");
        }
        set<node>::iterator it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);//找到这个数但cnt还没加所以删掉 
        book[num]++;
        s.insert(node{num, book[num]});//插入自动排序 
    }
    return 0;
}
