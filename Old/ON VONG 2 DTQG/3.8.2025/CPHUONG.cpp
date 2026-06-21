#include <bits/stdc++.h>
using namespace std;
long long n;
bool check (long long n){
    long long s1 =sqrt(n);
    if (s1 * s1 == n) return true;
    else return false;
}
void subtask1(){
    vector <long long> a;
    for (int i = 2; i < n; i++){
        if (check(i)) a.push_back(i);
    }
    long long m = a.size();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            for (int k = 0; k < m; k++){
                for (int l = 0; l < m; l++){
                    // cerr << sqrt(a[i]) << ' ' << sqrt(a[j]) << ' ' << sqrt(a[k]) << ' ' << sqrt(a[l]) << endl;
                    if ((a[i] + a[j] + a[k] + a[l]) == n){
                        cout << sqrt(a[i]) << ' ' << sqrt(a[j]) << ' ' << sqrt(a[k]) << ' ' << sqrt(a[l]);
                        return;
                    }
                }
            }
        }
    }
    cout << -1;
    return;
}
#define task "CPHUONG"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    // if (check(n)) cout << -1;
    // else{
    //     subtask1();
    // }
    subtask1();
    return 0;
}