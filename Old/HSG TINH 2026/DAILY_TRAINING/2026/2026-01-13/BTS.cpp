/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BTS"
int n;
vector <int> a, s;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    s.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int top = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        while(top > 0 && s[top] < a[i]){
            ans++;
            top--;
        }
        if (top > 0){
            ans++;
            if (s[top] == a[i]){
                top--;
            }
        }
        top++;
        s[top] = a[i];
    }
    cout << ans << endl;
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
