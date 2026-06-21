#include <bits/stdc++.h>
using namespace std;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    long long dem = 0;
    
    do {
        dem++;
    } while(next_permutation(s.begin(), s.end()));
    
    long long kq = 0;
    while(dem % 10 == 0){
        kq++;
        dem = dem / 10;
    }
    
    cout << kq << endl;
    
    return 0;
}