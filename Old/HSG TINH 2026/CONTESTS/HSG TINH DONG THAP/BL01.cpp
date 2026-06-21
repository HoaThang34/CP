/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BL01"
long long n;
unordered_map<long long, long long> cnt;
bool check(long long n){
    long long du = sqrt(n);
    return du*du == n;
}
void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long x;
        cin >> x;
        cnt[x]++;
    }
    long long i = 0;
    while (true){
        if (cnt[i] == 0 && check(i)){
            cout << i << endl;
            return;
        }
        i++;
    }
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
