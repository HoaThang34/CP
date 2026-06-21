/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "D"
int n, m;
long long h;
vector<long long> a, o;
vector <int> v;
vector<bool> vs;

void hoathang(){
    cin >> n >> m >> h;
    a.resize(n + 5);
    o.resize(n + 5);
    vs.assign(n + 5, false);
    v.clear();
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        o[i] = a[i];
    }
    for (int i = 1; i <= m; i++){
        int b; long long c;
        cin >> b >> c;
        a[b] += c;
        if (!vs[b]){
            vs[b] = true;
            v.push_back(b);
        }
        if (a[b] > h){
            for (int x : v){
                a[x] = o[x];
                vs[x] =false;
            }
            v.clear();
        }
    }
    for (int i = 1;i <= n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
