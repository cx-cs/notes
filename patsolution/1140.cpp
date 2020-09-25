#include <iostream>
#include<cstdio>
using namespace std;
int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        for (int i = 0; i < s.length(); i = j) {
            for (j = i; j < s.length() && s[j] == s[i]; j++);
            char tmp[40]="";
            sprintf(tmp,"%d",j-i);
            t += s[i] + string(tmp);
        }
        s = t;
    }
    cout << s;
    return 0;
}
