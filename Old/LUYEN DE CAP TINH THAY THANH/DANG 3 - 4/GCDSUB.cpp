/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

const int MAXN = 100005;
const int LOGN = 18;
int st[MAXN][LOGN];
int lg[MAXN];

void build(const vector<int>& a, int n) {
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i/2] + 1;
    
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];

    for (int j = 1; j < LOGN; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = gcd(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}

int query(int L, int R) {
    int j = lg[R - L + 1];
    return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    build(a, n);

    // Binary search for length
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        bool found = false;
        // Check if there exists subarray of length mid with GCD > 1
        for (int i = 0; i <= n - mid; ++i) {
            if (query(i, i + mid - 1) > 1) {
                found = true;
                break;
            }
        }
        if (found) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
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
