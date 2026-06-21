#include <bits/stdc++.h>
using namespace std;
long long m, n, g, r, c;
vector<string> s;

#define task "APPLEFALL"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    s.resize(m + 1);
    for (int i = 1; i <= m; i++){
        cin >> s[i];
    } 
    cin >> g;
    while (g--){
        cin >> r >> c;
        long long ans = LLONG_MAX;
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (s[i][j - 1] == 'x'){
                    long long dx = i - r;
                    long long dy = j - c;
                    long long d2 = dx * dx + dy * dy;
                    if (d2 < ans) ans = d2;
                }
            }
        }
        cout << ans << endl;
        s[r][c - 1] = 'x';
    }
    return 0;
}
