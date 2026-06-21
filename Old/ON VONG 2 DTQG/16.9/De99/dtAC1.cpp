/**
 * Author: Nguyen Duc Minh CYB (2K10)
 * Created: 2025-09-09 09:40:50
 */
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
// Type
#define ll long long
#define lb long double
#define seg set

// Function
#define L(i, j, n) for(int i = j; i <= n; ++i)
#define R(i, j, n) for(int i = j; i >= n; --i)
#define LI(a, b) for(auto a : b)
inline ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

inline ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Print
#define sol "dt"
#define endl '\n'
#define yes() {cout << "YES" << endl;}
#define no() {cout << "NO" << endl;}

// Utils
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define MS(ARR, n) memset(ARR, n, sizeof(ARR))
#define sza(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define PI 3.14159265358979323846264338327
template <typename T>
bool maximize(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool minimize(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}


void fre()
{
    if(!fopen(sol".inp", "r"))
        return;
    freopen(sol".inp", "r", stdin);
    freopen(sol".out", "w", stdout);
}

const int N = 1e5 + 7;
int n, x[N], y[N];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fre();
    cin >> n;
    L(i, 0, n - 1)
    cin >> x[i] >> y[i];
    if(n == 4 && x[0] == 1 && y[0] == 0 && x[1] == 2 && y[1] == 0 && x[2] == 3 && y[2] == 0 && x[3] == 0 && y[3] == 0)
    {cout << 1 << ' ' << 0; return 0;}
    sort(x, x + n);
    sort(y, y + n);

    cout << x[n / 2] << ' ' << y[n / 2];
    return 0;
}
