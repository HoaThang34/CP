/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "bai4"

long long n;
long long t;
vector<pair<long long, long long>> a;

void hoathang(){
    cin >> n >> t;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    priority_queue<long long> pq;
    long long s1 = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        long long n1 = a[i].first;
        long long n2 = a[i].second;
        s1 += n2;
        pq.push(n2);
        while (!pq.empty() && n1 + s1 > t){
            s1 -= pq.top();
            pq.pop();
        }
        ans = max(ans, (int)pq.size());
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
