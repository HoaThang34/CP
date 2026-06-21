/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

#define nap ""

void hoathang(){
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<long long> a(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i];
    }

    bool hasB = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            hasB = true;
            break;
        }
    }

    if (!hasB) {
        for (int i = 0; i < q; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    vector<int> next_b(n);
    vector<int> dist(n);
    vector<int> cost(n);
    vector<int> b_pos;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            b_pos.push_back(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(b_pos.begin(), b_pos.end(), i);
        
        int target_b;
        if (it == b_pos.end()) {
            target_b = b_pos[0];
        } else {
            target_b = *it;
        }

        next_b[i] = target_b;
        dist[i] = (target_b - i + n) % n;

        int c = 0;
        for (int k = 0; k < dist[i]; ++k) {
            if (s[(i + k) % n] == 'A') {
                c++;
            }
        }
        cost[i] = c;
    }

    for (int i = 0; i < q; ++i) {
        long long cur_a = a[i];
        long long time = 0;
        int pos = 0;
        
        int threshold = 2 * n;

        while (cur_a > threshold) {
            int d = dist[pos];
            int c = cost[pos];
            int target_pos = next_b[pos];

            time += d;
            cur_a -= c;
            pos = target_pos;

            time++;
            cur_a /= 2;
            pos = (pos + 1) % n;
        }

        while (cur_a > 0) {
            time++;
            if (s[pos] == 'A') {
                cur_a--;
            } else {
                cur_a /= 2;
            }
            pos = (pos + 1) % n;
        }
        
        cout << time << endl;
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
    cin >> t;
    
    while (t--){
        hoathang();
    }
    
    return 0;
}