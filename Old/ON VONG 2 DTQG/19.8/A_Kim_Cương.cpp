#include <bits/stdc++.h>
using namespace std;
long long m, n;
#define int long long
vector<vector<char>> a;
bool check(long long x, long long y, long long k){
    if(x - k < 1||x + k > m||y - k < 1||y + k > n) return false;
    for(long long dx = -k; dx <= k; dx++){
        long long rem = k - abs(dx);
        for(long long dy = -rem; dy <= rem; dy++){
            long long i = x + dx, j = y + dy;
            if(abs(dx) + abs(dy) == k){
                if(a[i][j]!='#') return false;
            }
            else{
                if(a[i][j]!='.') return false;
            }
        }
    }
    return true;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector<char> (n + 1, '.'));
    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) a[i][j] = s[j-1];
    }
    long long ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            long long rmax = min(min(i - 1, m - i), min(j - 1,n - j));
            for(int k = 1; k <= rmax; k++){
                if(check(i,j,k)) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}








