/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap ""
int n;
long long k;
vector<int> a;
void sub1(){
    vector<int> f(n +5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long sum = f[j] - f[i - 1];
            if (sum == k ){
                d++;
            }
        }
    }
    cout << d<< endl;
}
// f[j] - f[i - 1] = k => f[j] = k + f[i - 1];
void sub2(){
    vector<int> f(n + 5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    long long d = 0;
    unordered_map<long long, long long> cnt;
    for (int i = 1; i <= n; i++){
        d += cnt[f[i] - k];
        cnt[f[i - 1]]++;
    }
    cout << d << endl;
}
void sub2_1(){
    unordered_map<long long, long long> cnt;
    long long s = 0, d = 0;
    for (int i = 1; i <= n; i++){
        long long x = a[i];
        s += x;
        d+=cnt[s - k];
        cnt[s]++;
    }
    cout << d<< endl;
}
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // sub1();
    // sub2();
    // if (n <= 5000) sub1();
    // else sub2();
    sub2_1();
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
