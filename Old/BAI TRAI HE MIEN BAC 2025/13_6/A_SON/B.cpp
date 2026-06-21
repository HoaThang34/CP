#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
ll n; vell a;
void sub1(){
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll max_val = 0;
        vector<ll> freq(n + 2, 0);
        for (ll j = i; j >= 0; j--) {
            max_val = max(max_val, a[j]);
            freq[a[j]]++;
            ll len = i - j + 1;
            if (max_val * (max_val + 1) / 2 != len) continue;
            bool ok = true;
            for (ll k = 1; k <= max_val; k++) {
                if (freq[k] != k) {
                    ok = false;
                    break;
                }
            }
            if (ok) res++;
        }
    }
    cout << res << '\n';
}
void sub2(){

    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll max_val = 0;
        vector<ll> freq(n + 2, 0);
        for (ll j = i; j >= 0; j--) {
            max_val = max(max_val, a[j]);
            freq[a[j]]++;
            ll len_req = max_val * (max_val + 1) / 2;
            ll cur_len = i - j + 1;
            if (cur_len > len_req) break;
            if (cur_len == len_req) {
                bool ok = true;
                for (ll k = 1; k <= max_val; k++) {
                    if (freq[k] != k) {
                        ok = false;
                        break;
                    }
                }
                if (ok) res++;
            }
        }
    }
    cout << res << '\n';
}
void sub3(){
    const int M_max = 450;
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<ll> hval(M_max + 2);
    for (int i = 1; i <= M_max; ++i) hval[i] = rng();

    vector<ll> prefix_hash(n + 1, 0);
    for (ll i = 0; i < n; ++i) prefix_hash[i + 1] = prefix_hash[i] + hval[a[i]];
    vector<ll> target_hash(M_max + 2, 0);
    for (int m = 1; m <= M_max; ++m)
        target_hash[m] = target_hash[m - 1] + m * hval[m];
    vector<int> L(n), R(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) st.pop();
        L[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && a[st.top()] < a[i]) st.pop();
        R[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll m = a[i];
        if (m > M_max) continue;
        ll len_req = m * (m + 1) / 2;
        int l = L[i] + 1, r = R[i] - 1;
        int left_cnt = i - l, right_cnt = r - i;
        if (left_cnt < right_cnt) {
            for (int j = i; j >= l; --j) {
                int k = j + len_req - 1;
                if (k > r) break;
                if (i < j || i > k) continue;
                ll cur_hash = prefix_hash[k + 1] - prefix_hash[j];
                if (cur_hash == target_hash[m]) ++res;
            }
        } else {
            for (int k = i; k <= r; ++k) {
                int j = k - len_req + 1;
                if (j < l) break;
                if (i < j || i > k) continue;
                ll cur_hash = prefix_hash[k + 1] - prefix_hash[j];
                if (cur_hash == target_hash[m]) ++res;
            }
        }
    }
    cout << res + 1 << '\n';
}
void solve(){
    long long ans=0;
    int km=0;
    while(1LL*(km+1)*(km+2)/2<=n)km++;
    for(int k=1;k<=km;k++){
        int L=k*(k+1)/2;
        vector<int>c(k+1);
        int bd=0,mt=0;
        for(int i=0;i<L;i++){
            if(a[i]>k)bd++;
            else c[a[i]]++;
        }
        for(int i=1;i<=k;i++)if(c[i]==i)mt++;
        if(bd==0&&mt==k)ans++;
        for(int l=0,r=L;r<n;l++,r++){
            if(a[l]>k)bd--;
            else{
                int v=a[l];
                if(c[v]==v)mt--;
                c[v]--;
                if(c[v]==v)mt++;
            }
            if(a[r]>k)bd++;
            else{
                int v=a[r];
                if(c[v]==v)mt--;
                c[v]++;
                if(c[v]==v)mt++;
            }
            if(bd==0&&mt==k)ans++;
        }
    }
    cout<<ans;
}
#define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    solve();
    return 0;
}