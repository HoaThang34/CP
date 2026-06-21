#include <bits/stdc++.h>
using namespace std;
int n, k;
string t;
int a[101][101][31][31];
bool solve(int l, int r, int mb, int ob){
    if(mb >= k) return false;
    if(ob >= k) return true;
    if(l > r) return true;
    if(a[l][r][mb][ob] != -1){
        return a[l][r][mb][ob];
    }
    bool wl = !solve(l + 1, r, ob, mb + (t[l] == 'B'));
    bool wr = !solve(l, r - 1, ob, mb + (t[r] == 'B'));
    return a[l][r][mb][ob] = (wl || wr);
}
#define task "RBGAME"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        t = s.substr(i) + s.substr(0, i);
        memset(a, -1, sizeof(a));
        if(solve(0, n - 1, 0, 0)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}