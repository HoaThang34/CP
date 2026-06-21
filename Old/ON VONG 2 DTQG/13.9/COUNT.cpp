#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
void subtask1(){
    int d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (((a[i]%m)*(a[j]%m)%m*(a[k]%m))%m==0){
                    d++;
                }
            }
        }
    }
    cout << d;
}
void subtask2(){
    int d = 0;
    vector <long long> dem(m, 0);
    for (int i = 1; i <= n; i++){
        dem[a[i] % m]++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            long long g = (a[i] % m) * (a[j] % m) % m;
            for (int k = 0; k < m; k++){
                if ((g * k) % m == 0){
                    d += dem[k];
                }
            }
        }
    }
    cout << d;
}
#define task "COUNT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }    
    subtask1();
    // if (n <= 200){
    //     subtask1();
    // }
    // else{
    //     subtask2();
    // }
    // subtask2();
    return 0;
}