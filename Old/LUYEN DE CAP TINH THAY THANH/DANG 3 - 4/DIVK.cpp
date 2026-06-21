/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    unordered_map<long long, long long> mp;
    mp.reserve(n * 2);

    long long s = 0, ans = 0;
    mp[0] = 1;

    for(int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        s = (s + x) % k;
        if(s < 0) s += k;
        ans += mp[s];
        mp[s]++;
    }

    cout << ans;
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
