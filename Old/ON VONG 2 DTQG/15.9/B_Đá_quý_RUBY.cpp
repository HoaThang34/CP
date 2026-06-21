#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void subtask1(){
    set<long long> st;
    int p = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        st.insert(a[i]);
        ans = max(ans, (long long)st.size());
        if (i - p != st.size()){
            p = i - 1;
            // for (long long x:st){
            //     cerr << x << ' ';
            // }
            // cerr << '\n';
            st.clear();
            st.insert(a[i]);
        }
    }
    cout << ans;
}
void subtask2(){
    map<long long, int> mp;
    long long ans = 0, l = 1;
    for (int r = 1; r <= n; r++){
        mp[a[r]]++;
        while (mp[a[r]] > 1){
            mp[a[r]]--;
            l++;
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;
}
#define task "ruby"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask1();
    subtask2();
    return 0;
}