#include <bits/stdc++.h>
using namespace std;
long long  m, n;
vector <vector <char>> a;
bool check(int x1, int y1, int x2, int y2){
    for(int j = y1; j <= y2; j++){
        if(a[x1][j] == 'X') return false;
    }
    for(int j = y1; j <= y2; j++){
        if(a[x2][j] == 'X') return false;
    }
    for(int i = x1 + 1; i < x2; i++){
        if(a[i][y1] == 'X') return false;
    }
    for(int i = x1 + 1; i < x2; i++){
        if(a[i][y2] == 'X') return false;
    }
    return true;
}
void subtask1(){
    long long rmax = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            for(int i1 = i; i1 <= m; i1++){
                for(int j1 = j; j1 <= n; j1++){
                    if(check(i, j, i1, j1)){
                        long long s = (i1 - i + 1) * (j1 - j + 1);
                        rmax = max(rmax, s);
                    }
                }
            }
        }
    }
    cout << rmax;
}
#define task "md"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <char> (n + 1));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    subtask1();
    return 0;
}