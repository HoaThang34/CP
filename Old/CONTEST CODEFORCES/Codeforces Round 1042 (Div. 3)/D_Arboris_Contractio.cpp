/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
vector<vector<long long>> ds_ke;
long long so_phep_bien_doi;
long long duyet(long long u, long long cha){
    long long so_nhanh_le = 0;
    for (long long v : ds_ke[u]){
        if (v == cha){
            continue;
        }
        so_nhanh_le += duyet(v, u);
    }
    if (so_nhanh_le == 0){
        return 1;
    }
    so_phep_bien_doi += so_nhanh_le - 1;
    return 1;
}
void hoathang(){
    long long n;
    cin >> n;
    ds_ke.assign(n + 1, vector<long long>());
    for (int i = 0; i < n - 1; i++){
        long long u, v;
        cin >> u >> v;
        ds_ke[u].push_back(v);
        ds_ke[v].push_back(u);
    }
    if (n == 2){
        cout << 0 << endl;
        return;
    }
    so_phep_bien_doi = 0;
    long long goc = 0;
    for (int i = 1; i <= n; i++){
        if (ds_ke[i].size() > 1){
            goc = i;
            break;
        }
    }
    long long so_nhanh_o_goc = 0;
    for(long long v : ds_ke[goc]){
        so_nhanh_o_goc += duyet(v, goc);
    }
    so_phep_bien_doi += so_nhanh_o_goc;
    cout << so_phep_bien_doi << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}