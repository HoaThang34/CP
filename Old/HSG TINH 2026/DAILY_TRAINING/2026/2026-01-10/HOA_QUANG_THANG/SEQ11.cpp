/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SEQ11"
int n;
vector <int> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long ans1 = 0;
    long long ans2 = -1e18;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++){
        if (i > 1 && a[i] > a[i - 1]){
            cnt++;
            ans1 += a[i];
        }
        else{
            cnt = 1;
            ans1 = a[i];
        }
        if (cnt > sum){
            sum = cnt;
            ans2 = ans1;
        }
        else if (cnt == sum){
            ans2 = max(ans2, ans1);
        }
    }
    cout << ans2 << endl;
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
