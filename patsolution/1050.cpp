#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    unordered_set<char>s;
    for(auto c:s2)
        s.insert(c);
    for(auto c:s1)
        if(s.find(c)==s.end())
            putchar(c);
    return 0;
}