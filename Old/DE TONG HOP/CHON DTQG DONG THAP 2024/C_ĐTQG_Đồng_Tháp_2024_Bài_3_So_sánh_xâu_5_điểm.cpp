#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long a, b, c, d;
string s;
void subtask1(){
    string sub1 = s.substr(a - 1, b - a + 1);
    string sub2 = s.substr(c - 1, d - c + 1);
    if(sub1 < sub2){
        cout << 0 << '\n';
    } else if(sub1 > sub2){
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

#define task "BAI3"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s;
    cin >> q;
    while(q--){
        cin >> a >> b >> c >> d;
        subtask1();
    }
    return 0;
}