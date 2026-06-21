// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
const long long N = 1000005;
long long t, a, b;
vector <long long> s;
vector <long long> dem;
vector <long long> f1 (N, 0);
vector <long long> f2 (N, 0);
long long demuoc(long long n){
    int d = 0;
    for (long long i = 1; i * i <= n; i++){
        if (n % i == 0){
            d++;
            if (i != n/i) d++;
        }
    }
    return d;
}
void tonguoc(){
    for (long long i = 1; i <= N; i++){
        for (long long j = i; j <= N; j+=i){
            s[j] += i;
        }
    }
}
void demu(){
    for (long long i = 1; i <= N; i++){
        for (long long j = i; j <= N; j+=i){
            dem[j]++;
        }
    }
}
void subtask1(){
    cin >> a >> b;
    int d = 0;
    long long sum = 0;
    for (long long i = a; i <= b; i++){
        d += demuoc(i);
        sum += s[i];
    }
    cout << d << ' ' << sum << endl;
}
void subtask2(){
    cin >> a >> b;
    long long d = f2[b] - f2[a - 1];
    long long sum = f1[b] - f1[a - 1];
    cout << d << ' ' << sum << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    s.resize(N + 1);
    dem.resize(N + 1);
    tonguoc();
    demu();
    cin >> t;
    for (int i = 1; i <= N; i++){
        f1[i] = f1[i - 1] + s[i];
        f2[i] = f2[i - 1] + dem[i];
    }
    while(t--){
        // subtask1();
        subtask2();
    }
    return 0;
}