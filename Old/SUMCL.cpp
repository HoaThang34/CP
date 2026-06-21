/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SUMCL"
int n;
long long s1 = 0, s2 = 0;

void hoathang(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x % 2 == 0){
            s1 += x;
        }
        else s2 += x;
    }
    cout << s1 << endl << s2 << endl;
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
