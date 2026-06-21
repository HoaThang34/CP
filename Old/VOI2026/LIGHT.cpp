/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "LIGHT"

int n, q, x, y;
vector <int> a;
vector <vector <int>> d;
void hoathang(){
    cin >> n >> q >> x >> y;
    a.resize(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    while(q--){
        int l, r, c1 = 0, c2 = 0;
        cin >> l >> r;
        for(int i = l; i <= r; i++){
            if(a[i] == 1) c1++;
            if(a[i] == 2) c2++;
        }
        int len = r - l + 1;
        d.resize(55, vector<int>(55, -1));
        queue<pair<int, int>> q;
        q.push({c1, c2});
        d[c1][c2] = 0;
        int ans = -1;
        while(q.size()){
            pair<int, int> u = q.front(); q.pop();
            int u1 = u.first, u2 = u.second, u0 = len - u1 - u2;
            if(u1 == 0 && u2 == 0){
                ans = d[u1][u2];
                break;
            }
            for(int i = 0; i <= x; i++){
                for(int j = 0; j <= x - i; j++){
                    int k = x - i - j;
                    for(int p = 0; p <= y; p++){
                        for(int s = 0; s <= y - p; s++){
                            int t = y - p - s;
                            if(i + p <= u1 && j + s <= u2 && k + t <= u0){
                                int v1 = (u1 - i - p) + k + s;
                                int v2 = (u2 - j - s) + i + t;
                                if(v1 < 55 && v2 < 55 && d[v1][v2] == -1){
                                    d[v1][v2] = d[u1][u2] + 1;
                                    q.push({v1, v2});
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
