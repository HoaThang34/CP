/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "CPNT"
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i*i < N; i++){
        if (f[i]){
            for (int j = i*i; j < N; j+=i){
                f[j] = false;
            }
        }
    }
}
vector <long long> p(N, 0);
void sangtong(){
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j+=i){
            p[j] += i;
        }
    }
}
bool check(int n){
    int du = sqrt(n);
    int ans = du*du;
    if (ans == n) return true;
    else return false;
}
vector <int> pre1(N, 0);
vector <long long> pre2(N, 0);
bool checknt(long long x) {
    if (x < 2) return false;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void prefixsum(){
    for (int i = 1; i < N; i++){
//            cerr << i << " ";
        if (check(i)){
            pre2[i] = pre2[i - 1] + i;
//            if(p[i] > N + 7) cerr << "mmb";
            if (p[i] < N && f[p[i]]){
                pre1[i] = pre1[i - 1] + 1;
            }
            else if (checknt(p[i])){
                pre1[i] = pre1[i - 1] + 1;
            }
        }
        else{
            pre2[i] = pre2[i - 1] + 0;
            pre1[i] = pre1[i - 1] + 0;
        }
    }
}
int a, b;
void hoathang(){
    cin >> a >> b;
//    cerr << a << " " << b << "\n";
    cout << pre2[b] - pre2[a - 1] << ' ';
    cout << pre1[b] - pre1[a - 1] << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    sangtong();
    prefixsum();
//    cerr << 1;
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
