#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int prel, int inl, int inr) {
    if (inl > inr || flag == true) return;
    int i = inl;
    while (in[i] != pre[prel]) i++;//找到中序根下标 
    postOrder(prel+1, inl, i-1);
    postOrder(prel+i-inl+1, i+1, inr);//左子树右子树访问完才到根（输出） 
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    postOrder(0, 0, n-1);
    return 0;
}
