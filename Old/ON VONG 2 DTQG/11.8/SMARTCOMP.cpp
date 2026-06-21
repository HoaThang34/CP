#include <bits/stdc++.h>
using namespace std;
long long n, v;
vector <pair<long long, long long>> g1, g2, g3, g4;
void subtask1(){
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                for (int t = 1; t <= n; t++){
                    long long c = g1[i].first + g2[j].first + g3[k].first + g4[t].first;
                    if (c <= v){
                        long long val = g1[i].second + g2[j].second + g3[k].second + g4[t].second;
                        ans = max(ans, val);
                    }
                }
            }
        }
    }
    cout << ans;
}
#define task "SMARTCOMP"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> v;
    g1.resize(n + 1);
    g2.resize(n + 1);
    g3.resize(n + 1);
    g4.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> g1[i].first >> g1[i].second;
    }
    for (int i = 1; i <= n; i++){
        cin >> g2[i].first >> g2[i].second;
    }
    for (int i = 1; i <= n; i++){
        cin >> g3[i].first >> g3[i].second;
    }
    for (int i = 1; i <= n; i++){
        cin >> g4[i].first >> g4[i].second;
    }
    cout << endl << "hello world";
    subtask1();
    return 0;
}
