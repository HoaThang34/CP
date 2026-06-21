/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "FONUSDIS"
int n;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] =false;
    for (int i = 2; i*i <= N; i++){
        if (f[i]){
            for (int j = i*i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
void hoathang(){
    cin >> n;
    int d = 0;
    while(n--){
        int x;
        cin >> x;
        if (!f[x]) d++;
    }
    cout << d << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    sang();
    hoathang();
    return 0;
}
