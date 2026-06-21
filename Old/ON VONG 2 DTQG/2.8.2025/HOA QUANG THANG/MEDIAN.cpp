#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;
void subtask1(){
    long long l = 1, r = k;
    while (r <= n){
        // cerr << l << ' ' << r << endl;
        vector <long long> b;
        for (int i = l; i <= r; i++){
            b.push_back(a[i]);
            // cerr << a[i] << ' ';
        }
        sort(b.begin(), b.end());
        // for (long long x : b) cerr << x << ' ';
        // cerr << endl;
        cout << b[b.size()/2] << ' ';
        l++; r++;
    }
}
void subtask2(){
    vector <pair<long long, long long>> b;
    for (int i = 0; i < n; i++){
        b.push_back({a[i + 1], i + 1}); //{gia tri, chi so ban dau}
    }
    sort (b.begin(), b.end());
    // for (auto x : b) cerr << x.first << ' ' << x.second << endl;
    long long l = 1, r = k; 
    while (r <= n){
        long long d = 0;
        // cerr << l << ' ' << r << endl;
        for (auto x : b){
            if (x.second >= l && x.second <= r){
                d++;
                // cerr << x.first << ' ' << x.second << endl;
                if (d == k/2 + 1){
                    cout << x.first << ' ';
                    // cerr << "lay " << x.first << ' ' << x.second << endl;
                    break;
                }
            }
        }
        l++; r++;
    }
}
#define task "MEDIAN"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n ; i++){
        cin >> a[i];
    }   
    if (n <= 2000){
        subtask1();
    }
    else subtask2();
    // subtask1();
    // subtask2();
    return 0;
}