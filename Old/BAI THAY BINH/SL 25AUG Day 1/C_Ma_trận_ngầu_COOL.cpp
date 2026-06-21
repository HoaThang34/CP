#include <bits/stdc++.h>
using namespace std;
long long m,n;
vector <vector <long long>> a;
bool check1(int x1, int y1, int x2, int y2){
    return a[x1][y1] + a[x2][y2] <= a[x1][y2] + a[x2][y1];
}
bool check2(int x1, int y1, int x2, int y2){
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            for(int u = i + 1; u <= x2; u++){
                for(int v = j + 1; v <= y2; v++){
                    if(!check1(i, j, u, v)) return false;
                }
            }
        }
    }
    return true;
}
void subtask1(){
    long long ans = LLONG_MIN;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int u = i + 1; u <= m; u++){
                for(int v = j + 1; v <= n; v++){
                    if(check2(i, j, u, v)){
                        ans = max(ans, (long long) (u - i + 1) * (v - j + 1));
                    }
                }
            }
        }
    }
    if (ans == LLONG_MIN) cout << 0;
    else cout << ans;
}
#define task "COOL"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }    
    subtask1();
    return 0;
}