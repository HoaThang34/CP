#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
vector <pair<long long, long long>> b;
set<long long> st;
void subtask1(){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long rmin = LLONG_MAX, s = 0;
    for (int i = 1; i <= n; i++){
        long long p = 0;
        for (int j = 1; j <= m; j++){
            if (b[j].second == 0){
                continue;
            }
            long long k = abs(a[i] - b[j].first);
            if (k <= rmin){
                p = b[j].first;
                rmin = k;
                b[j].second--;
            }
        }
        s += abs(a[i] - p);
    }
    cout << s;
}
#define task "ROBOT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize (n + 1);
    b.resize (m + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i].first >> b[i].second;
    }
    subtask1();
    return 0;
}