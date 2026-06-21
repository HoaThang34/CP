#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool check1(long long i, long long n){
    return (i <= n); 
}
bool check2(long long x,long long k){
    string a=to_string(x);
    string b=to_string(k);
    return a<=b;
}
void subtask1(){
    int d = 0;
    for (int i = 1; i <= n; i++){
        if (check1(i, n) && check2(i, k)){
            d++;
            // cerr << i << endl;
        }
    }
    cout << d;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    subtask1();
    return 0;
}