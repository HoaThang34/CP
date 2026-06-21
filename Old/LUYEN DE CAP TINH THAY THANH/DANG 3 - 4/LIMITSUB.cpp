/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

void hoathang(){
    int n, k;
    cin >> n>> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    vector<long long> s(n+1, 0);
    for(int i=0; i<n; ++i) s[i+1] = s[i] + a[i];

    deque<int> dq;
    dq.push_back(0);
    long long ans = -1e18;

    for(int i=1; i<=n; ++i){
        // Remove indices out of range [i-k, i-1]
        // Corresponding index in s is j. subarray sum = s[i] - s[j].
        // Length condition: len <= k => i - j <= k => j >= i - k.
        while(!dq.empty() && dq.front() < i - k) dq.pop_front();
        
        if (!dq.empty()) {
            ans = max(ans, s[i] - s[dq.front()]);
        }

        while(!dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << ans;
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
