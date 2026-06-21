#include <bits/stdc++.h>
using namespace std;
long long n, p;
vector <long long> a;
void subtask1(){
    long long rmax = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (a[j] - a[i] >= p){
                if (rmax < (j - i)){
                    rmax = (j - i);
                    // cerr << i << ' ' << j << endl;
                }
            }
        }
    }
    cout << rmax;
}
#define task "JUMP"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> p;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    subtask1();
    return 0;
}