#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
long long n;
vector <long long> a;

#define task "songca"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    unordered_map<long long, int> mp;
    long long d = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        d = d + mp[a[i]];
        mp[a[i]]++;
    }
    cout << d;
    return 0;
}