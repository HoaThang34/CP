#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void subtask1(){
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long rmax = max(a[i], a[j]);
            bool check = false;
            for (int k = i + 1; k < j; k++){
                if (a[k] >= rmax){
                    check = true;
                    break;
                }
            }
            if (check == false) d++;
        }
    }
    cout << d;
}
void subtask2(){
    long long d = 0;
    long long rmax = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        rmax = a[i];
        for (int j = i + 1; j <= n; j++){
            rmax = max(rmax, a[j]);
            if (rmax == a[i]) d++;
            else{
                if (rmax == a[j]) d++;
                else{
                    continue;
                }
            }
        }
    }
    cout << d;
}
#define task "TEAM24"
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
    // subtask1();
    // subtask2();
    // subtask3();
    if (n <= 100) subtask1();
    else subtask2();
    return 0;
}

// tat ca cac phan tu tu l -> r se nho hon max(a[l], a[r]);
// nghia la max [l -> r] la a[l] hoac a[r];