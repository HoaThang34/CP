/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define nap "GROUP"
#define endl '\n'
#define int long long
int n, k;
vector<int> a;

void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin() + 1, b.begin() + 1 + n);
    vector <int> c;
    c.resize(n + 5);
    for (int i = 1; i <= n; i++){
        c[i] = lower_bound(b.begin() + 1, b.begin() + 1 + n, a[i]) - b.begin() + 1;
    }
    int s = 0;
    for (int i = 1; i <= k; i++){
        s += c[i];
    }
    int rmax = s;
    int pos = 1;
    for (int i = 2; i + k - 1 <= n; i++){
        s = s - b[i - 1] + b[i + k - 1];
        if (s > rmax){
            rmax = s;
            pos = i;
        }
    }
    cout << pos << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
