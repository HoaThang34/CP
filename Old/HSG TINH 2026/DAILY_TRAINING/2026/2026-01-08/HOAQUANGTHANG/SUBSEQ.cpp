/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SUBSEQ"
int n;
vector <int> a;
void sub1(){
    int rmax = -1e9;
    for (int i = 1; i <= n; i++){
        vector <int> ans;
        int l = i;
        ans.push_back(a[l]);
        for (int r = i + 1; r <= n; r++){
            if (a[r] % a[l] == 0){
                ans.push_back(a[r]);
                l = r;
            }
        }
        rmax = max(rmax, (int)ans.size());
    }
    cout << rmax << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sub1();
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
