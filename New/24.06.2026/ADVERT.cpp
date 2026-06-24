/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "ADVERT"
#define endl '\n'
#define int long long
int m, n;
vector <pair<int,int>> a;
void sub1(){
    vector <int> ans(m + 5, 0);
    for (int i = 1; i <= n; i++){
        for (int j = a[i].first; j <= a[i].second; j++){
            ans[j] = i;
        }
    }
    map<int,int> cnt;
    for (int i = 1; i <= m; i++){
        cnt[ans[i]]++;
    }
    int d = 0;
    for (int i = 1; i <= n; i++){
        int dis = a[i].second - a[i].first + 1;
        if (dis == cnt[i]){
            d++;
        }
    }
    cout << d << endl;
}
vector<int> par;
int find(int v){
    if (v != par[v]) par[v] = find(par[v]);
    return par[v];
}

void unite(int u, int v){
    int p = find(u);
    while (p <= v){
        par[p] = find(p + 1);
        p = find(p);
    }
}
void sub2(){
    par.assign(n + 5, 0);
    for (int i = 1; i <= m; i++){
        par[i] = i;
    }
    int ans = 0;
    for (int i = n; i >= 1; i--){
        pair<int,int> p = a[i];
        int u = p.first;
        int v = p.second;
        if (find(u) <= v){
            ans++;
            unite(u, v);
        }
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> m >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }    
    // sub1();
    // sub2();
    if (n <= 2000 & m <= 2000){
        sub1();
    }
    else sub2();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
