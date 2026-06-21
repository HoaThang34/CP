#include <bits/stdc++.h>
using namespace std;
long long k;
#define task "TAPDINH"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> k;
    vector<pair<long long, long long>> a(k);
    long long rmax = 0;
    for(int i = 0; i < k; i++){
        cin >> a[i].first >> a[i].second;
        rmax = max(rmax, a[i].second);
    }
    set<long long> st;
    queue<long long> q;
    if (2 <= rmax){
        q.push(2);
        st.insert(2);
    }
    while(!q.empty()){
        long long v = q.front();
        q.pop();
        long long x = 2 * v + 1;
        if(x <= rmax && st.find(x) == st.end()){
            st.insert(x);
            q.push(x);
        }
        long long y = 3 * v;
        if(y <= rmax && st.find(y) == st.end()){
            st.insert(y);
            q.push(y);
        }
    }
    vector<long long> v(st.begin(), st.end());
    for(int i = 0; i < k; i++){
        long long u = a[i].first;
        long long vv = a[i].second;
        auto it1 = lower_bound(v.begin(), v.end(), u);
        auto it2 = upper_bound(v.begin(), v.end(), vv);
        cout << (it2 - it1) << '\n';
    }
    return 0;
}