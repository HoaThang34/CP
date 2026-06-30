/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap ""
#define endl '\n'
#define int long long
int n;
vector<int> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int l = 1;
    int ans = 0;
    map<int,int> cnt;
    for (int r = 1; r <= n; r++){
        cnt[a[r]]++;
        while(cnt[a[r]] > 1){
            cnt[a[l]]--;
            l++;
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
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
