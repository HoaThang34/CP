/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "KHOINGHIEP"
int n;
vector <int> a, b;
void sub2(){
    sort(b.begin() + 1, b.begin() + 1 + n);
    long long s = 0;
    int d = 0;
    for (int i = 1; i <= n; i++){
        if (d == a[1]) break;
        d++;
        s += b[i];
    }
    cout << s << endl;
}
void sub3(){
    sort(a.begin() + 1, a.begin() + 1 + n);
    int d = 0;
    long long s = 0;
    for (int i = 1; i <= n; i++){
        while(d < a[i]){
            d++;
            s += b[1];
        }
        d++;
    }
    cout << s << endl;
}
vector <pair<int, int>> p;
priority_queue<int, vector<int>, greater<int>> pq;
void sub14(){
    sort(p.begin() + 1, p.begin() + 1 + n, greater<pair<int,int>>());
    int d = 0;
    long long s = 0;
    int r;
    for (int l = 1; l <= n; l = r){
        r = l;
        while (r <= n && p[r].first == p[l].first){
            pq.push(p[r].second);
            r++;
        }
        int k = p[l].first - (n - (r - 1));
        while (d < k && !pq.empty()){
            s += pq.top(); pq.pop();
            d++;
        }
    }
    cout << s << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    b.resize(n + 5);
    p.resize(n + 5);
    bool ok1 = true, ok2 = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        p[i] = {a[i], b[i]};
        if (a[i] != a[i - 1] && i > 1){
            ok1 = false;
        }
        if (b[i] != b[i - 1] && i > 1){
            ok2 = false;
        }
    }
    if (ok1){
        sub2();
    }
    else if (ok2) sub3();
    else sub14();
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
