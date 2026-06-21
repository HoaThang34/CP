/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "hoathang"
#define int long long
int n;
int k;
vector<int> a;
bool cmp(long long a, long long b){
    return a > b;
}
void sub1(){
    sort(a.begin() + 1, a.begin() + k + 1, cmp);
    int pos = 0;
    int cnt = 0;
    for (int i = 1; i <= k; i++){
        if (pos < a[i]){
            int dis = n - a[i];
            pos += dis;
            cnt++;
        }
        else break;
    }
    cout << cnt << endl;
}
void hoathang(){
    cin >> n >> k;
    a.resize(k + 5);
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    sub1();
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t--){
        hoathang();
    }
    return 0;
}
