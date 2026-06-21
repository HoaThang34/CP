/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "flowers"

int n;
long long m;
vector<long long> f, s;
vector<int> ans;
bool check(int n){
    long long k = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] <= n){
            k += f[i];
            if (k >= m) return true;
        }
        else k = 0;
    }
    return false;
}
void hoathang(){
    cin >> n >> m;
    f.resize(n + 5);
    s.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> f[i] >> s[i];
        ans.push_back(s[i]);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    int l = 0, r = ans.size() - 1;
    int res = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(ans[mid])){
            res = ans[mid];
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    cout << res << endl;
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
