#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n, m;
    string a, b, c;
    cin >> n >> a >> m >> b >> c;
    deque<char> dq;
    for(char x : a){
        dq.push_back(x);
    }
    for(long long i = 0; i < m; i++){
        if(c[i] == 'V'){
            dq.push_front(b[i]);
        }else{
            dq.push_back(b[i]);
        }
    }
    for(char x : dq){
        cout << x;
    }
    cout << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}