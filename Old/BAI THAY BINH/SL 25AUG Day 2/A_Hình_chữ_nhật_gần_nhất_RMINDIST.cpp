#include <bits/stdc++.h>
using namespace std;
long long m, n, a, b;
vector<vector<long long>> vt;
vector<vector<long long>> pre;
long long sum(long long i1, long long j1, long long i2, long long j2){
    return pre[i2][j2] - pre[i1 - 1][j2] - pre[i2][j1 - 1] + pre[i1 - 1][j1 - 1];
}
void subtask1(){
    long long ans = LLONG_MAX;
    for(long long i1 = 1; i1 <= m; i1++){
        for(long long j1 = 1; j1 <= n; j1++){
            for(long long i2 = i1; i2 <= m; i2++){
                for(long long j2 = j1; j2 <= n; j2++){
                    long long s = sum(i1, j1, i2, j2);
                    ans = min(ans, abs(s - a) + abs(s - b));
                }
            }
        }
    }
    cout << ans << endl;
}
void subtask2(){
    long long ans = LLONG_MAX;
    if(a > b){
        swap(a, b);
    }
    for(long long i1 = 1; i1 <= m; i1++){
        for(long long i2 = i1; i2 <= m; i2++){
            set<long long> vs;
            vs.insert(0);
            long long sum1 = 0;
            for(long long j = 1; j <= n; j++){
                sum1 += sum(i1, j, i2, j);
                long long a1 = sum1 - b;
                set<long long>::iterator it = vs.lower_bound(a1);
                if(it != vs.end()){
                    long long s = sum1 - *it;
                    ans = min(ans, abs(s - a) + abs(s - b));
                }
                if(it != vs.begin()){
                    it--;
                    long long s = sum1 - *it;
                    ans = min(ans, abs(s - a) + abs(s - b));
                }
                vs.insert(sum1);
            }
        }
    }
    cout << ans << endl;
}
#define task "RMINDIST"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n >> a >> b;
    vt.resize(m + 1, vector<long long>(n + 1));
    pre.resize(m + 1, vector<long long>(n + 1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> vt[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + vt[i][j];
        }
    }
    if(m <= 50 && n <= 50){
        subtask1();
    }else{
        subtask2();
    }
    return 0;
}