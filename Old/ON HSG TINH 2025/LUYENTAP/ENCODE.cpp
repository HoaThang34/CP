/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "encode"

void hoathang(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool ok = false;
        for(int i = 1; i <= 26; i++){
            for(int j = 1; j <= 26; j++){
                int k = n - i - j;
                if(k >= 1 && k <= 26){
                    cout << (char)('a' + i - 1);
                    cout << (char)('a' + j - 1);
                    cout << (char)('a' + k - 1);
                    cout << endl;
                    ok = true;
                    break;
                }
            }
            if(ok){
                break;
            }
        }
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