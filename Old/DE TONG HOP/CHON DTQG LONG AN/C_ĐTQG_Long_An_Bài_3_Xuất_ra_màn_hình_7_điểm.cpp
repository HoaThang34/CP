#include <bits/stdc++.h>
using namespace std;
long long m, n;
vector <vector <long long>> a;
vector <vector <long long>> f;
void subtask1(){
    f.resize(m + 1, vector <long long> (n + 1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i-1][j - 1] + a[i][j];
        }
    }
    long long ans = -1e18;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            for (int i1 = i; i1 <= m; i1++){
                for (int j1 = j; j1 <= n; j1++){
                    long long sum = f[i1][j1] - f[i - 1][j1] - f[i1][j - 1] + f[i - 1][j - 1];
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans;
}
void subtask2(){
    long long ans = -1e18;
    for (int i = 1; i <= m; i++){
        vector<long long> f1(n + 1, 0);
        for (int i1 = i; i1 <= m; i1++){
            for (int j = 1; j <= n; j++){
                f1[j] += a[i1][j];
            }
            long long s = 0;
            long long rmax = -1e18;
            for (int j = 1; j <= n; j++){
                s += f1[j];
                rmax = max(rmax, s);
                if (s < 0){
                    s = 0;
                }
            }
            ans = max(ans, rmax);
        }
    }
    cout << ans;
}
#define task "bangso"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    f.resize(m + 1, vector <long long> (n + 1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i-1][j - 1] + a[i][j];
        }
    }
    // subtask1();
    subtask2();
    return 0;
}