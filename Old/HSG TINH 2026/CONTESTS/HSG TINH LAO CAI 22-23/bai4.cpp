/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai4"
int n;
vector<long long> a;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n - 2; i++){
        for (int j = i + 1; j <= n - 1; j++){
            long long sum = a[i] + a[j];
            int l = j + 1, r = n, pos = j;
            while (l <= r){
                int mid = (l + r) / 2;
                if (a[mid] < sum){
                    pos = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans += pos - j;
        }
    }
    cout << ans;
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
