/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "shortsub_neg"

long long n, s, ans;
vector<long long> a, p;
deque<int> dq;

void hoathang(){
    if (!(cin >> n >> s)) return;
    a.resize(n + 5);
    p.resize(n + 5);
    ans = n + 1;
    p[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++){
        while (!dq.empty() && p[i] - p[dq.front()] >= s){
            ans = min(ans, (long long)i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && p[i] <= p[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    if (ans > n) cout << -1;
    else cout << ans;
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