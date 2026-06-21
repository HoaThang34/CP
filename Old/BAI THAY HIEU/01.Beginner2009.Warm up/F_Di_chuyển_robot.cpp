#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long x = 0, y = 0;
long long h = 0;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        if(s[i] == 'G'){
            if(h == 0) y = y + 1;
            if(h == 1) x = x + 1;
            if(h == 2) y = y - 1;
            if(h == 3) x = x - 1;
        }
        if(s[i] == 'L'){
            h = h - 1;
            if(h == -1) h = 3;
            if(h == 0) y = y + 1;
            if(h == 1) x = x + 1;
            if(h == 2) y = y - 1;
            if(h == 3) x = x - 1;
        }
        if(s[i] == 'R'){
            h = h + 1;
            if(h == 4) h = 0;
            if(h == 0) y = y + 1;
            if(h == 1) x = x + 1;
            if(h == 2) y = y - 1;
            if(h == 3) x = x - 1;
        }
        if(s[i] == 'B'){
            h = h + 2;
            if(h == 4) h = 0;
            if(h == 5) h = 1;
            if(h == 6) h = 2;
            if(h == 0) y = y + 1;
            if(h == 1) x = x + 1;
            if(h == 2) y = y - 1;
            if(h == 3) x = x - 1;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}