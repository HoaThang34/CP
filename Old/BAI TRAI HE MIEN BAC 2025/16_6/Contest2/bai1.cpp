#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
long long n;
vector <long long> a;
void subtask1(){
    for (int i = 0; i <n; i++){
        int d = 0;
        for (int j = 0; j < n; j++){
            if ((a[i] & a[j]) == a[j]){
                    d++;
            }
        }
        cout << d << endl;
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
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    subtask1();
    return 0;
}