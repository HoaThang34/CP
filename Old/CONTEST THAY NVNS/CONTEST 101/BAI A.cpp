/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "sol"

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void hoathang(){
    int n;
    cin >> n;

    int best = 1e9, h, m;

    for (int i = 0; i < 24; ++i)
        for (int j = 0; j < 60; ++j){
            int s = a[i/10] + a[i%10] + a[j/10] + a[j%10];
            if (s == n && i * 60 + j < best){
                best = i * 60 + j;
                h = i;
                m = j;
            }
        }

    if (best == 1e9)
        cout << "Impossible";
    else
        cout << setfill('0') << setw(2) << h << ":" << setw(2) << m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();
    return 0;
}