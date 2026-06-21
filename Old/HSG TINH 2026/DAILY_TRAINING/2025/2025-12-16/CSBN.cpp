/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "CSBN"
int n;
void hoathang(){
    cin >> n;
    map<int, long long> cnt;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    long long ans = 0;
    for (pair <int, long long> p : cnt){
        ans += p.second*(p.second - 1)/2;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
