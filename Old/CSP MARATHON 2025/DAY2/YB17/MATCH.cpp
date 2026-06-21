#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
long long l, r;
vector <long long> a, b;
vector <long long> ans;
bool checkk(vector <long long> ans){
    vector <long long> res;
    long long rmin = LLONG_MAX;
    long long pmin = 0;
    for (int i = 0; i < ans.size(); i++){
        res.push_back(ans[i]);
        if (rmin > ans[i]){
            rmin = ans[i];                    
            pmin = i;
        }
    }
    for (int i = 0; i < ans.size(); i++){
        res.push_back(ans[i]);
    }
    for (int i = pmin; i < pmin + ans.size() - 1; i++){
        for (int j = i + 1; j < pmin + ans.size() - 1; j++){
            if (res[i] > res[j]) return false;
        }
    }
    return true;
}
void subtask1(){
    ans.clear();
    set<long long> st;
    for (int i = l; i <= r; i++){
        st.insert(a[i]);
        ans.push_back(a[i]);
    }
    bool check = true;
    for (int i = 1; i <= m; i++){
        auto it = st.find(b[i]);
        if (it != st.end()){
            st.erase(it);
        }
        else{
            check = false;
            break;
        }
    }
    if (!check) cout << "NO" << endl;
    else{
        if (checkk(ans)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m >> q;
    a.resize(n + 1);
    b.resize(m + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    while (q--){
        cin >> l >> r;
        subtask1();
    }
    return 0;
}