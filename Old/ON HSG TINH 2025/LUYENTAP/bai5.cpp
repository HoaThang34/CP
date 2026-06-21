/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai5"

int n;
long long l, w, h;
vector<pair<long long, long long>> p;
vector<tuple<long long, long long, long long, int>> events;
vector<long long> Y;
vector<int> min_val, lazy;
int sz;

void push(int v) {
    if (lazy[v] == 0) {
        return;
    }
    min_val[2 * v] += lazy[v];
    lazy[2 * v] += lazy[v];
    min_val[2 * v + 1] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add) {
    if (l > r) {
        return;
    }
    if (l == tl && r == tr) {
        min_val[v] += add;
        lazy[v] += add;
        return;
    }
    push(v);
    int tm = tl + (tr - tl) / 2;
    update(2 * v, tl, tm, l, min(r, tm), add);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, add);
    min_val[v] = min(min_val[2 * v], min_val[2 * v + 1]);
}

bool check(int k) {
    long long lx = l - w;
    long long ly = l - h;
    if (lx < 0 || ly < 0) {
        return true;
    }

    events.clear();
    vector<long long> y_coords;
    y_coords.reserve(2 * k + 2);
    y_coords.push_back(0);
    y_coords.push_back(ly + 1);

    for (int i = 1; i <= k; ++i) {
        long long x_drop = p[i].first;
        long long y_drop = p[i].second;
        long long x1 = max(0LL, x_drop - w);
        long long x2 = min(lx, x_drop);
        long long y1 = max(0LL, y_drop - h);
        long long y2 = min(ly, y_drop);
        if (x1 <= x2 && y1 <= y2) {
            events.emplace_back(x1, y1, y2, 1);
            events.emplace_back(x2 + 1, y1, y2, -1);
            y_coords.push_back(y1);
            y_coords.push_back(y2 + 1);
        }
    }

    if (events.empty()) {
        return false;
    }

    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    Y = y_coords;

    sz = Y.size() - 1;
    if (sz <= 0) {
        return true;
    }

    min_val.assign(4 * sz + 5, 0);
    lazy.assign(4 * sz + 5, 0);

    sort(events.begin(), events.end());

    if (get<0>(events[0]) > 0) {
        return false;
    }

    for (int i = 0; i < events.size(); ) {
        long long current_x = get<0>(events[i]);
        if (current_x > lx) {
            break;
        }

        int j = i;
        while (j < events.size() && get<0>(events[j]) == current_x) {
            long long y1_ev = get<1>(events[j]);
            long long y2_ev = get<2>(events[j]);
            int type_ev = get<3>(events[j]);

            int y_idx1 = lower_bound(Y.begin(), Y.end(), y1_ev) - Y.begin();
            int y_idx2 = lower_bound(Y.begin(), Y.end(), y2_ev + 1) - Y.begin();

            update(1, 0, sz - 1, y_idx1, y_idx2 - 1, type_ev);
            j++;
        }

        long long next_x = lx + 1;
        if (j < events.size()) {
            next_x = get<0>(events[j]);
        }

        if (current_x < next_x) {
            if (min_val[1] == 0) {
                return false;
            }
        }
        i = j;
    }

    return true;
}

void hoathang(){
    cin >> n >> l >> w >> h;
    p.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    int low = 1;
    int high = n;
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
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
