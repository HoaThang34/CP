#include <bits/stdc++.h>
using namespace std;
long long m, n, k;
vector <vector <long long>> a;
vector <vector <long long>> pre;
void subtask1(){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    long long d = 0;
    for (int u = 1; u <= m; u++){
        for (int v = 1; v <= n; v++){
            for (int p = u; p <= m; p++){
                for (int q = v; q <= n; q++){
                    long long sum = pre[p][q] - pre[u - 1][q] - pre[p][v - 1] + pre[u - 1][v - 1];
                    if (sum % k == 0){
                        d++;
                    }
                }
            }
        }
    }
    cout << d;
}
#define task "table24"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n >> k;
    a.resize(m + 1, vector <long long> (n + 1));
    pre.resize(m + 1, vector <long long> (n + 1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    subtask1();
    return 0;
}