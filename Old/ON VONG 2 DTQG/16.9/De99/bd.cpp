#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
vector <long long> f;
long long gcd (long long a, long long b){
    long long tmp;
    while (b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void pstg(long long &x,long long &y){
    long long g = gcd(x,y);
    x/=g;
    y/=g;
}
long long xuli(long long n){
    long long x = 1;
    long long y = n;
    while (y > 1){
        x++;
        y--;
        pstg(x, y);
    }
    return x;
}
#define task "bd"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = a[i] * a[i] * a[i];
    }
    for (int i = 1; i <= n; i++){
        cout << xuli(a[i]) << '\n';
    }
    return 0;
}
