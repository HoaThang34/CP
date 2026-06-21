/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

const int LIM = 200001;

int T, n;
vector<int> a;
vector<int> spf;
vector<int> cnt;
vector<int> touch;

void build(){
    spf.resize(LIM + 1, 0);
    spf[1] = 1;
    for (int i = 2; i <= LIM; i++){
        if (spf[i] == 0){
            spf[i] = i;
            if (1LL * i * i <= LIM){
                for (int j = i * i; j <= LIM; j += i){
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }
    }
    cnt.resize(LIM + 1, 0);
}

void fac(int x, vector<int> &v){
    v.clear();
    while (x > 1){
        int p = spf[x];
        v.push_back(p);
        while (x % p == 0) x /= p;
    }
}

void hoathang(){
    build();

    cin >> T;

    while (T--){
        cin >> n;

        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool ok0 = false;

        vector<int> v;

        for (int i = 0; i < n; i++){
            fac(a[i], v);
            for (int p : v){
                if (cnt[p] == 0) touch.push_back(p);
                cnt[p]++;
                if (cnt[p] >= 2) ok0 = true;
            }
        }

        if (ok0){
            cout << 0 << endl;
        } else {
            bool ok1 = false;

            for (int i = 0; i < n && !ok1; i++){
                int x = a[i] + 1;
                fac(x, v);
                for (int p : v){
                    if (cnt[p] >= 1){
                        ok1 = true;
                        break;
                    }
                }
            }

            if (ok1) cout << 1 << endl;
            else cout << 2 << endl;
        }

        for (int p : touch) cnt[p] = 0;
        touch.clear();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}
