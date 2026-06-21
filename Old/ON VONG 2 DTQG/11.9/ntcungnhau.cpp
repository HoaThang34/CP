#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
long long gcd (long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
void subtask1(){
    vector <long long> ans;
    for (long long i = 1; i <= m; i++){
        bool ok = true;
        for (int j = 1; j <= n; j++){
            if (gcd(i, a[j]) != 1){
                ok = false;
                break;
            }
        }
        if (ok){
            ans.push_back(i);
        }
    }   
    cout << ans.size() << '\n';
    for (long long x : ans){
        cout << x << '\n';
    }
}
void subtask2(){
    set<long long> st;
    for (int i = 1; i <= n; i++){
        long long num = a[i];
        for (long long j = 2; j * j <= num; j++){
            if (num % j == 0){
                st.insert(j);
                while (num % j == 0){
                    num /= j;
                }
            }
        }
        if (num > 1){
            st.insert(num);
        }
    }
    vector<bool> f(m + 1, true);
    f[0] = false;
    for (long long p : st){
        for (long long j = p; j <= m; j += p){
            f[j] = false;
        }
    }
    vector<long long> ans;
    for(long long i = 1; i <= m; i++){
        if(f[i]){
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (long long x : ans){
        cout << x << '\n';
    }
}
#define task "sol"
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
    // subtask1();
    // subtask2();
    if (n * m <= 1e6){
        subtask1();
    }
    else{
        subtask2();
    }
    return 0;
}