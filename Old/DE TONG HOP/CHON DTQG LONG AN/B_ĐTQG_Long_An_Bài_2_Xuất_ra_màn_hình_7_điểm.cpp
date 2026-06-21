#include <bits/stdc++.h>
#include <vector>
using namespace std;
long long m, n;
vector <vector <long long>> a, b;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector <vector<bool>> vs;
void dfs(long long x, long long y, vector <long long>& ans){
    vs[x][y] = true;
    ans.push_back(a[x][y]);
    for (int i = 0; i < 4; i++){
        long long x1 = x + dx[i], y1 = y + dy[i];
        if (x1 >= 1 && x1 <= m && y1 >= 1 && y1 <= n && vs[x1][y1] == false && a[x1][y1] != 0){
            dfs(x1, y1, ans);
        }
    }
}
#define task "khaithac"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    b.resize(m + 1, vector <long long> (n + 1));
    vs.resize(m + 1, vector<bool> (n + 1, false));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    } 
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }    
    long long res1 = LLONG_MIN, res2 = LLONG_MAX;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            vector <long long> res;
            if (!vs[i][j] && a[i][j] != 0){
                dfs(i, j, res);
                long long s = 0;
                for (long long x : res){
                    s += x;
                }
                if (s > res1){
                    res1 = s;
                    res2 = res.size();
                }   
                else if (s == res1 && res2 > res.size()){
                    res2 = res.size();
                }
            }
        }
    }
    cout << res1 << ' ' << res2;
    return 0;
}