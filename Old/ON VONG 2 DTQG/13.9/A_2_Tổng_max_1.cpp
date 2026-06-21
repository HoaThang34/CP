#include <bits/stdc++.h>
using namespace std;
long long n, sum;
vector <long long> a;

#define task ""
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> sum;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    set<long long> st;
    st.insert(0);
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        vector <long long> tmp;
        for (long long x : st){
            long long s = x + a[i];
            if (s <= sum){
                tmp.push_back(s);
            }
        }
        for (long long x : tmp){
            st.insert(x);
            ans = max(ans, x);
        }
    }
    cout << ans;
    return 0;
}