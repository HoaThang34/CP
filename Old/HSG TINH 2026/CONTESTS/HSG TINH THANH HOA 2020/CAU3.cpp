/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU3"
string ss;
void hoathang(){
    cin >> ss;
    int n = ss.size();
    int s = 0;
    vector <int> f(n + 5, 0);
    for (int i = 1; i <= n; i++){
        int x = ss[i - 1] - '0';
        s += x;
        f[i] = f[i - 1] + x;
    }
    int d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int sum = f[j] - f[i - 1];
            if ((s - sum) % 3 == 0){
                d++;
            }
        }
    }
    cout << d << endl;
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
