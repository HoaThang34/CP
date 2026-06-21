/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "PICTURE"
int n, m;
vector <pair<int, int>> a;
vector <int> c;
void hoathang(){
    cin >> n >> m;
    a.resize(n +5);
    c.resize(m + 5);
    for (int i = 1; i <= n;  i++){
        cin >> a[i].first >> a[i].second;

    }
    for (int i = 1; i <=  m; i++){
        cin >> c[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(c.begin() + 1, c.begin() + 1 + n);
    multiset<int> st;
    int j = 1, ans = 0;
    int k = 0;
    for (int i = 1; i <= m; i++){
        while (j <= n && a[j].first <= c[i]){
            st.insert(a[j].second);
            j++;
        }
        auto it = st.lower_bound(k);
        if (it != st.end()){
            k = *it;
            ans++;
            st.erase(it);
        }
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
