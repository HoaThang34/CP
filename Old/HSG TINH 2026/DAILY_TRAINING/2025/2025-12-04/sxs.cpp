/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sxs"
int n;
vector<string> a;

bool cmp(string x, string y){
    return x + y > y + x;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
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
