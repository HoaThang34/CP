#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
vector <long long> a;
void subtask1(){
    int d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (a[i] * a[j] == i + j){
                d++;
            }
        }
    }
    cout << d << '\n';
}
#define task "cs"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        subtask1();
    }
    return 0;
}