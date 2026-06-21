#include <bits/stdc++.h>
using namespace std;
long long m, n;
vector<vector<long long>> a;
void subtask1(){
    long long ans = 0;
    for(int r1 = 1; r1 <= m; r1++){
        for(int r2 = r1; r2 <= m; r2++){
            for(int c1 = 1; c1 <= n; c1++){
                for(int c2 = c1; c2 <= n; c2++){
                    bool check = true;
                    long long sum = 0;
                    for(int i = r1; i <= r2; i++){
                        for(int j = c1; j <= c2; j++){
                            if(a[i][j] == -1){
                                check = false;
                                break;
                            }
                            sum += a[i][j];
                        }
                        if(!check) break;
                    }
                    if(check) ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans;
}
#define task "MINERAL"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    subtask1();
    return 0;
}