#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma,bmi,bmi2,lzcnt,popcnt")
#include <ext/random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define ll long long
#define ld long double
#define vtn 3004
#define fmax 1000007
#define fi first
#define se second
#define sp << " "
#define el << "\n"
#define oo 1e18
// #define int ll
#define pii pair<int,int>
#define pb push_back
#define FOD(i,b,a) for(int i = (int)b; i >= (int)a; i--)
#define FOR(i,a,b) for(int i = (int)a; i <= (int)b; i++)
#define le node * 2, l, mid
#define ri node * 2 + 1, mid + 1, r
#define whole(_x_) _x_.begin(), _x_.end()
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
template<class T> inline bool maximize(T &r, const T &v) {return r < v ? r = v, 1 : 0;}
template<class T> inline bool minimize(T &r, const T &v) {return r > v ? r = v, 1 : 0;}
//0x3f = oo

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ran(ll l, ll r) {if(l <= r) return uniform_int_distribution <ll> (l, r)(rng); return -1;} 
ll n;
void solve(){
    cin >> n;
    
}  

#define NAME ""
signed main(){
    faster
    if(fopen(NAME".inp", "r")){
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    int test = 1;
    // cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
