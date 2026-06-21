#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long n, q;
vector <long long> a;
set <long long> st;
vector <bool> Q(N, false);
#define task "DELGAME"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }
    for (long long x : st){
        for (long long i = x; i <= N; i+=x){
            Q[i] = true;
        }
    }
    int d = 0;
    for (long long i = 1; i <= q; i++){
        if (Q[i]){
            d++;
        }
    }
    cout << d;
    return 0;
}