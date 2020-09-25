#include <iostream>
#include<cstdio> 
#include <vector>
using namespace std;
vector<int> v;
int a[1009], n, isMin = 1, isMax = 1;
void dfs(int index) {//用之前写法更好 
    if (index * 2 > n) {
        if (index <= n) {
            for (int i = 0; i < v.size(); i++)
                printf("%d%s", v[i], i != v.size() - 1 ? " " : "\n");//输出模板 
        }
    } else {
        v.push_back(a[index * 2 + 1]);
        dfs(index * 2 + 1);
        v.pop_back();
        v.push_back(a[index * 2]);
        dfs(index * 2);
        v.pop_back();
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    v.push_back(a[1]);
    dfs(1);
    for (int i = 2; i <= n; i++) {//判断大根小根 
        if (a[i/2] > a[i]) isMin = 0;
        if (a[i/2] < a[i]) isMax = 0;
    }
    if (isMin == 1)
        printf("Min Heap");
    else 
        printf("%s", isMax == 1 ? "Max Heap" : "Not Heap"); 
    return 0;
}
