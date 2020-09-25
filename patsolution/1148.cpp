#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {//������ 
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;//-1��ʾ���� 
            for (int k = 1; k <= n; k++)//С��0˵����k����˵�� 
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);//v[k]�ǵ�k����˵��,abs(v(k))��˵�����ǲ������� 
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {//2����˵����ֻ��һ������ 
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}
