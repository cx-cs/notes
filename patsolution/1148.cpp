#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {//暴力法 
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;//-1表示狼人 
            for (int k = 1; k <= n; k++)//小于0说明第k个人说谎 
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);//v[k]是第k个人说的,abs(v(k))是说的人是不是狼人 
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {//2个人说谎且只有一个狼人 
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}
