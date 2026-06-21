/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "CHARSORT"
int n;
int k, cnt;
vector<int> p;
vector<int> a;
vector<bool> f(N, 1);
void sang(){
    f[0] = f[1] = 0;
    for (int i = 2; i * i <= N; i++){
        if (f[i]){
            for (int j = i * i; j <= N; j += i)
                f[j] = 0;
        }
    }
    for (int i = 2; i <= N; i++){
        if (f[i]) p.push_back(i);
    }
    cnt = p.size();
}

int demuoc(long long x){
    if (x <= 0) return 0;
    if (x == 1) return 1;
    int r = 1;
    long long t = x;
    for (int i = 0; i < cnt; i++){
        if ((long long)p[i] * p[i] > t) break;
        if (t % p[i] == 0){
            int c = 0;
            while (t % p[i] == 0){
                c++;
                t /= p[i];
            }
            r *= (c + 1);
        }
    }
    if (t > 1) r *= 2;
    return r;
}
void hoathang(){
    string s;
    cin >> s >> k;
    int n = s.size();
    a.resize(n + 5);
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
    do{
        long long x = 0;
        for (int i = 1; i <= n; i++) x = x * 10 + a[i];
        if (demuoc(x) == k) {
            cout << x << endl;
            return;
        }
    }while (prev_permutation(a.begin() + 1, a.begin() + n + 1));
    cout << "NONE" << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    hoathang();
    return 0;
}
