/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai4"
long long n, t;
vector<pair<long long, long long>> a;
bool check(int k){
    if (k == 0) return true;
    if (k > n) return false;
    multiset<long long> s, l;
    long long ss = 0;
    for (int j = 1; j <= n; j++){
        if (!s.empty() && a[j].second < *s.rbegin()){
            l.insert(*s.rbegin());
            ss -= *s.rbegin();
            s.erase(prev(s.end()));
            s.insert(a[j].second);
            ss += a[j].second;
        }
        else
            l.insert(a[j].second);
        while (s.size() < k && !l.empty()){
            ss += *l.begin();
            s.insert(*l.begin());
            l.erase(l.begin());
        }
        if (s.size() == k) {
            if (ss + a[j].first <= t){
                return true;
            }
        }
    }
    long long cnt = 0;
    for (int i = 1; i <= k; i++){
        cnt += a[i].second;
    }
    for (int i = 1; i <= n - k + 1; i++){
        if (i > 1) {
            cnt = cnt - a[i - 1].second + a[i + k - 1].second;
        }
        long long xi = a[i].first;
        long long xj = a[i + k - 1].first;
        if (cnt + 2 * xj - xi <= t || cnt + xj <= t){
            return true;
        }
    }
    return false;
}

void hoathang(){
    cin >> n >> t;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int l = 0, r = n, ans = 0;
    while (l <= r){
        int mid = l + (r - l) / 2;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans << endl;
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
