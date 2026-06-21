/*
    author: CHATGPT
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

bool isp(int x){
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int i = 3; 1LL * i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

vector<int> a;

void gen(int x){
    if (x > 100000000) return;
    a.push_back(x);
    int d[4] = {1, 3, 7, 9};
    for (int i = 0; i < 4; i++){
        long long y = 1LL * x * 10 + d[i];
        if (y <= 100000000 && isp((int)y))
            gen((int)y);
    }
}

void hoathang(){
    int n;
    cin >> n;
    int s[4] = {2, 3, 5, 7};
    for (int i = 0; i < 4; i++) gen(s[i]);
    int ans = -1;
    for (int x : a)
        if (x <= n) ans = max(ans, x);
    cout << ans;
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
