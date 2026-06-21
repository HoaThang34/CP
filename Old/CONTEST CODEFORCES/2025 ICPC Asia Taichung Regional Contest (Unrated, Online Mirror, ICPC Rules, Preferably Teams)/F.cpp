/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

struct E {
    int u, v;
    long long w;
};

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int i) {
        if (p[i] == i) return i;
        return p[i] = find(p[i]);
    }
    void unite(int i, int j) {
        int r_i = find(i);
        int r_j = find(j);
        if (r_i != r_j) {
            p[r_i] = r_j;
        }
    }
};

void hoathang(){
    int n;
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<E> es;
    vector<pair<int, long long>> st;

    for (int i = 0; i < n; ++i) {
        vector<pair<int, long long>> nst;
        nst.push_back({i, p[i]});
        for (const auto& [j, g] : st) {
            long long ng = __gcd(g, p[i]);
            if (ng == nst.back().second) {
                nst.back().first = j;
            } else {
                nst.push_back({j, ng});
            }
        }
        st = nst;
        for (const auto& [j, g] : st) {
            es.push_back({j, i, g});
        }
    }

    sort(es.begin(), es.end(), [](const E& a, const E& b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    long long cost = 0;
    int ecnt = 0;
    for (const auto& e : es) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            cost += e.w;
            ecnt++;
            if (ecnt == n - 1) {
                break;
            }
        }
    }

    cout << cost << endl;
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
