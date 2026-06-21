#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 8

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("sol.inp", "r")){
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }
    int n;
    cin >> n;
    vector <long long> a[N];
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < M; ++j){
            cin >> a[i][j];
        }
    }
    long long ans = -1145141919;
    for(int i = 0; i < M; ++i){
        long long temp = 0;
        for(int j = 1; j <= n; ++j){
            if (i % 2 == 0 && a[j][i] > a[j][i + 1]){
                temp += a[j][i];
            }
            else if (i % 2 != 0 && a[j][i] < a[j][i + 1]){
                temp += a[j][i];
            }
        }
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}