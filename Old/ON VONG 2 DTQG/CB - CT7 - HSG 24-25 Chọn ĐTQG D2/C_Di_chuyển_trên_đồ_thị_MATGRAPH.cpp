#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long n, k, t;
vector <long long> a;
vector <vector <long long>> matrix;
long long gcd(long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void subtask1(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i] == a[j]) continue;
            else{
                if (gcd(a[i], a[j]) == 1){
                    if (a[i] < a[j]){
                        matrix[i][j] = 1;
                    }
                    else{
                        matrix[j][i] = 1;
                    }
                }
            }
        }
    }
    matrix[1][n] = matrix[n][1] = 1;

}
#define task "MATGRAPH"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 1);
    matrix.assign(n + 1,vector <long long> (n + 1, 0));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> t;
    subtask1();
    while (t--){
        long long u, v;
        cin >> u >> v;
        cout << matrix[u][v] << endl;
    }
    return 0;
}