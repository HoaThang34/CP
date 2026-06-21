#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
void subtask1(){
    long long l, r;
    cin >> l >> r;
    vector <long long> ans;
    for (int i = l; i <= r; i++){
        ans.push_back(a[i]);
    }
    sort(ans.begin(), ans.end());
    long long sum = 0;
    for (int i = 1; i < ans.size(); i++){
        long long d = ans[i] - ans[i - 1];
        sum += d*d;
    }
    cout << sum << endl;
}
#define task "ESTPROG"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--){
        subtask1();
    }
    return 0;
}