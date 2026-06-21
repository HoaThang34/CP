#include <bits/stdc++.h>
using namespace std;
long long n;
bool check (long long n){
    set <long long> st;
    string s = to_string(n);
    for (char x : s){
        st.insert(x);
        if(st.size() > 2){
            return false;
        }
    }
    return true;
}
void solve(long long n){
    if (check(n)){
        cout << 0 << endl;
    }
    else{
        long long l = n - 1, r = n + 1;
        while (true){
            if (!check(r)) r--;
            else if (check(r)){
                cout << r << endl;
                break;
            }
            else if (!check(l)) l++;
            else if (check(l)){
                cout << l << endl;
                break;
            }
        }
    }
}
#define task "dihybrid"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    while (cin >> n){
        solve(n);
    }
    return 0;
}