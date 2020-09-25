#include <cstdio>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    bool operator < (const node a)  const{//���� 
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;//�ṹ�弯�� 
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;//���ϼ��� 
            for(set<node>::iterator it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);//it�ǽṹ��ָ�� 
                tempCnt++;
            }
            printf("\n");
        }
        set<node>::iterator it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);//�ҵ��������cnt��û������ɾ�� 
        book[num]++;
        s.insert(node{num, book[num]});//�����Զ����� 
    }
    return 0;
}
