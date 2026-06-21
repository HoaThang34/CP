#include <bits/stdc++.h>
using namespace std;
long long n;
void subtask1(long long n, long long m, const vector<string>& gr){
    vector<vector<vector<long long>>> pre(n + 1, vector<vector<long long>>(m + 1, vector<long long>(5, 0)));
    for(long long i = 1; i <= n; ++i){
        for(long long j = 1; j <= m; ++j){
            for(long long k = 0; k < 5; ++k){
                pre[i][j][k] = pre[i - 1][j][k] + pre[i][j - 1][k] - pre[i - 1][j - 1][k];
            }
            pre[i][j][gr[i - 1][j - 1] - 'A']++;
        }
    }
    long long ans = 0;
    for(long long r1 = 1; r1 <= n; ++r1){
        for(long long c1 = 1; c1 <= m; ++c1){
            for(long long r2 = r1; r2 <= n; ++r2){
                for(long long c2 = c1; c2 <= m; ++c2){
                    long long dis = 0;
                    for(long long k = 0; k < 5; ++k){
                        long long cnt = pre[r2][c2][k] - pre[r1 - 1][c2][k] - pre[r2][c1 - 1][k] + pre[r1 - 1][c1 - 1][k];
                        if(cnt > 0){
                            dis++;
                        }
                    }
                    if(dis == 3){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
#define task "TABLE"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<string> gr(n);
    long long m = 0;
    for(long long i = 0; i < n; ++i){
        cin >> gr[i];
    }
    if(!gr.empty()){
        m = gr[0].size();
    }
    subtask1(n, m, gr);
    return 0;
}