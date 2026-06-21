#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
vector <long long> b;
void subtask1(){
    long long sum = 0;
    for (int i = 1; i <= n - 2; i++){
        long long x = b[i];
        sum += (a[x - 1] + a[x + 1]) * a[x];
        for (int i = x; i <= n; i++){
            a[i] = a[i + 1];
        }
    }
    cout << sum;
}
#define task "MARBLES"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int j = 1; j <= n - 2; j++){
        cin >> b[j];
    }
    subtask1();
    return 0;
}