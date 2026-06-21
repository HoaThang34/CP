#include <bits/stdc++.h>
using namespace std;
long long n;
bool checkk(long long n){
    string s = to_string(n);
    for (char x : s){
        if (x != '0' && x != '4' && x != 9){
            return false;
        }
    }
    return true;
}
void subtask1(){
    long long i = 0;
    long long s = 0;
    while (true){
        long long k = s * s;
        if (checkk(k)){
            i++;
            if (i == n){
                cout << s;
            }
        }
        s++;
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    subtask1();
    return 0;
}