/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "DINDV"
long long n, d;
vector <long long> a;
vector <long long> v;
vector <long long> bit_l, bit_r;
int m;

void update(vector<long long>& bit, int idx, int val) {
    for (; idx <= m; idx += idx & -idx) {
        bit[idx] += val;
    }
}

long long query(vector<long long>& bit, int idx) {
    long long res = 0;
    for (; idx > 0; idx -= idx & -idx) {
        res += bit[idx];
    }
    return res;
}

int get_rank(long long val) {
    return lower_bound(v.begin(), v.end(), val) - v.begin() + 1;
}

int get_upper_rank(long long val) {
    return upper_bound(v.begin(), v.end(), val) - v.begin();
}

void sub2() {
    for (int i = 1; i <= n; i++) {
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    m = v.size();
    bit_l.resize(m + 5, 0);
    bit_r.resize(m + 5, 0);
    for (int i = 2; i <= n; i++) {
        update(bit_r, get_rank(a[i]), 1);
    }
    long long ans = 0;
    update(bit_l, get_rank(a[1]), 1);
    for (int j = 2; j < n; j++) {
        update(bit_r, get_rank(a[j]), -1);
        long long req_i = a[j] + d;
        long long req_k = a[j] - d;
        int r_i = get_rank(req_i);
        long long c_i = query(bit_l, m) - query(bit_l, r_i - 1);
        int r_k = get_upper_rank(req_k);
        long long c_k = query(bit_r, r_k);
        ans += c_i * c_k;
        update(bit_l, get_rank(a[j]), 1);
    }
    cout << ans << endl;
}
void sub1(){
    long long dem = 0;
    for (int i = 1; i <= n - 2; i++){
        for (int j = i + 1; j <= n - 1; j++){
            for (int k = j + 1; k <= n; k++){
                if (a[i] - a[j] >= d && a[j] - a[k] >= d){
                    dem++;
//                    cerr << a[i] << ' ' << a[j] << ' ' << a[k] << endl << a[i] - a[j] << ' ' << a[j] - a[k] << endl;
                }
            }
        }
    }
    cout << dem << endl;
}
void hoathang(){
    cin >> n >> d;
//    cerr << n << ' ' << d << endl;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (n <= 1000) sub1();
    else sub2();
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
