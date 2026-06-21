#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;
long long rmin = LLONG_MAX;
void subtask1(){
    vector <long long> tmp = a;
    for (int i = 0; i < n; i++){
        vector <long long> tmp1 = a;
        swap(tmp1[i], tmp1[i + 1]);
        if (tmp1 < tmp){
            tmp = tmp1;
        }
    }
    for (long long x : tmp) cout << x << ' ';
}

#define task "order24"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (rmin > a[i]) rmin = a[i];
    }
    subtask1();
    return 0;
}