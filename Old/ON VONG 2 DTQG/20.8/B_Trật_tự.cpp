#include <bits/stdc++.h>
using namespace std;
long long n, m;
#define task "sol"
void subtask1(long long k, long long m){
    string s = to_string(k);
    for (long long x = k; x <= 1000; x++){
        vector<string> ans;
        for (int i = 1; i <= x; i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(), ans.end());
        long long p = -1;
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == s){
                p = i + 1;
                break;
            }
        }
        if (p == m){
            cout << x << endl;
            return;
        }
    }
    cout << 0 << endl;
}
void subtask2(long long k, long long m){
    string s = to_string(k);
    long long d = 0;
    for (int i = 1; i < k; i++){
        if (to_string(i) < s){
            d++;
        }
    }
    long long p = d + 1;
    if (m < p){
        cout << 0 << endl;
        return;
    }
    if (m == p){
        cout << k << endl;
        return;
    }
    long long dis = m - p;
    long long ans = 0;
    for (long long x = k + 1; x <= 1000005; x++){
        if (to_string(x) < s){
            dis--;
        }
        if (dis == 0){
            ans = x;
            break;
        }
    }
    if (ans != 0){
        cout << ans << endl;
    } else {
        cout << 0 << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    while(t--){
        long long k, m;
        cin >> k >> m;
        if (k <= 1000 && m <= 1000){
            subtask1(k, m);
        }
        else{
            subtask2(k, m);
        }
    }
    return 0;
}