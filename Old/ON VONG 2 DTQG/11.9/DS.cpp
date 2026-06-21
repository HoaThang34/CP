#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;

#define task "ds"
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
    priority_queue<long long> q;
    int d = 0;
    long long s = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] >= 0){
            s += a[i];
            d++;
        }
        else{
            if (s + a[i] >= 0){
                s += a[i];
                d++;
                q.push(abs(a[i]));
            }
            else if(!q.empty() && q.top() > abs(a[i])){
                s += a[i];
                s += q.top();
                q.pop();
                q.push(abs(a[i]));
            }
        }
    }
    cout << d;
    return 0;
}