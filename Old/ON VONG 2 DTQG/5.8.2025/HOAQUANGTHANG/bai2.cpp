#include <bits/stdc++.h>
using namespace std;
string s;
const long long N = 1e6 + 5;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i < N; i++){
        if (f[i]){
            for (int j = i*i; j < N; j+=i){
                f[j] = false;
            }
        }
    }
}
#define task "BAI2"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> s;
    s += 'a';
    vector <long long> a;
    long long n = s.size();
    string s1 = "";
    for (char x : s){
        if (isdigit(x)){
            s1 += x;
        }
        else{
            if (!s1.empty()){
                long long k = stoll(s1);
                a.push_back(k);
            }
            s1 = "";
        }
    }
    long long rmax = 0;
    for (long long x : a){
        // cerr << x << ' ';
        if (f[x]){
            rmax = max(rmax,  x);
        }
    }
    cout << rmax;
    return 0;
}