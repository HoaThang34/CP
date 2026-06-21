#include <bits/stdc++.h>
using namespace std;
long long t, m, n;
vector <vector<long long>> a;
long long res;

void dfs(long long i,long long j, vector <long long>& p){
    p.push_back(a[i][j]);
    if(i == m && j == n){
        vector <bool> check(p.size() + 2, false);
        for(long long x : p){
            if (x >= 0 && x <= p.size()) check[x] = true;
        }
        long long k = 0;
        while (check[k]) k++;
        res = max(res, k);
    }
    else{
        if (i < m){
            dfs(i+1, j, p);
        }
        if (j < n){
            dfs(i, j+1, p);
        }
    }
    p.pop_back();
}
void subtask1(){
    cin >> m >> n;
    a.resize(m + 1, vector<long long> (n + 1));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if(m == 1 || n == 1){
        set<long long> st;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                st.insert(a[i][j]);	
                // cerr << a[i][j] << ' ';
            }
        }
        long long k = 0;
        while(st.count(k)) k++;
        cout << k << endl;
    }
    else{
        vector<long long> p;
        res = 0;
        dfs(1, 1, p);
        cout << res << endl;
    }
}
#define task "MEX"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        subtask1();
    }
    return 0;
}