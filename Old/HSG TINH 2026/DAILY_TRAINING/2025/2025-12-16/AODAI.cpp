/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "AODAI"
int n;
vector <int> cnt;
void hoathang(){
    cin >> n;
    cnt.resize(5, 0);
    for (int i = 0; i < n; i++){
        int s;
        cin >> s;
        cnt[s]++;
    }
    int ans = 0;
    ans += cnt[4];
    cnt[4] = 0;
    ans += cnt[3];
    int rmin = min(cnt[3], cnt[1]);
    cnt[1] -= rmin;
    cnt[3] = 0;
    ans += cnt[2]/2;
    cnt[2]%=2;
    if (cnt[2] == 1){
        ans += 1;
        cnt[2] = 0;
        cnt[1] = max(0, cnt[1] - 2);
    }
    ans += (cnt[1] + 3)/4;
    cout << ans << endl;
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
