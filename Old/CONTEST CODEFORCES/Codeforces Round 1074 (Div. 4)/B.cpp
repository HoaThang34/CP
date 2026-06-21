/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "B"
int n;
vector <int> a;
long long xuli(int n, vector <int>&a){
    long long s =0 ;
    int rmax = -1e9;
    for (int i = 1; i <= n; i++){
        rmax = max(rmax, a[i]);
        s += rmax;
    }
    return s;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long ans = xuli(n, a);
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            swap(a[i], a[j]);
            ans = max(ans, xuli(n, a));
            swap(a[i], a[j]);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
