#include <bits/stdc++.h>
using namespace std;
#define task "sol"
const int MAXN = 1000007;
vector<bool> f(MAXN, true);
void sang(){
    f[0] = f[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(f[i]){
            for(long long j = 1LL * i * i; j < MAXN; j += i){
                f[j] = false;
            }
        }
    }
}
void sub1(const string& s){
    vector<char> a(s.begin(), s.end());
    sort(a.begin(), a.end());
    long long d = 0;
    do{
        long long x = 0;
        for(char c : a) x = x * 10 + (c - '0');
        if(x < MAXN && f[x]) d++;
    }while(next_permutation(a.begin(), a.end()));
    cout << d;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    sang();
    string s;
    cin >> s;
    sub1(s);
    return 0;
}

