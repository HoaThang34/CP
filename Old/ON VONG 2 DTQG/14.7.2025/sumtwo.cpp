#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void subtask1(){
    vector <long long> c;
    long long rmax = LLONG_MIN;
    long long rmin = LLONG_MAX;
    for (int i = 1; i <= n; i++){
        rmax = max(rmax, a[i] + a[i + 1]);
    }
    if (rmin > rmax){
        rmin = rmax;
        c.clear();
        for (int i = 1; i <= n; i++){
            c.push_back(a[i]);
        }
    }
    cout << rmin << endl;
    for (long long x : c){
        cout << x << ' ';
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    subtask1();
    return 0;
}