/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" 

int n, m;
vector<int> a[100005];
bool vis[100005];

void dfs(int u){
    vis[u] = true;
    for(int v : a[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void hoathang(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}