/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "twins"

long long n;
vector<long long> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    long long s = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1, greater<long long>());
    long long s1 = 0;
    long long cnt = 0;
    for (int i = 1; i <= n; i++){
        s1 += a[i];
        cnt++;
        if (s1 > s / 2){
            break;
        }
    }
    cout << cnt << endl;
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