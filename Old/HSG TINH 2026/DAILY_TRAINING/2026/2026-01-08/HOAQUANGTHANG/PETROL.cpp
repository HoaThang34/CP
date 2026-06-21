/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "PETROL"

struct Node {
    long long x, h;
};
int n;
long long d;
vector<Node> a;
vector<long long> v;
vector<int> lg;
vector<vector<long long>> st;

bool cmp(Node a, Node b) {
    if (a.x != b.x) return a.x < b.x;
    return a.h < b.h;
}
long long get(int l, int r) {
    if (l > r) return -1;
    int j = lg[r - l + 1];
    return max(st[j][l], st[j][r - (1 << j) + 1]);
}
void hoathang(){
    cin >> n >> d;
    a.resize(n + 5);
    v.resize(n + 5);
    lg.resize(n + 5);
    st.resize(30, vector <long long> (n + 5));
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].h;
    }
    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    for (int i = 1; i <= n; i++){
        v[i] = a[i].x;
    }
    for (int i = 1; i <= n; i++)
        st[0][i] = a[i].h;
    for (int j = 1; j <= 20; j++){
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        int l1 = lower_bound(v.begin() + 1, v.begin() + n + 1, a[i].x - d) - v.begin();
        int r1 = lower_bound(v.begin() + 1, v.begin() + n + 1, a[i].x) - v.begin() - 1;
        int l2 = upper_bound(v.begin() + 1, v.begin() + n + 1, a[i].x) - v.begin();
        int r2 = upper_bound(v.begin() + 1, v.begin() + n + 1, a[i].x + d) - v.begin() - 1;
        if (get(l1, r1) >= 2 * a[i].h && get(l2, r2) >= 2 * a[i].h) ans++;
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
