#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a;
vector <long long> pre;
void subtask1(){
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long sum = 0;
            for (int k = i; k <= j; k++){
                sum += a[k];
            }
            if (sum <= m) d++;
        }
    }
    cout << d;
}
void subtask2(){
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    long long d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = pre[j] - pre[i - 1];
            if (s <= m) d++;
        }
    }
    cout << d;
}
void subtask3(){
    long long d = 0;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        long long l = m + pre[i-1];
        long long j = upper_bound(pre.begin()+i, pre.begin()+n+1, l) - pre.begin();
        d += (j - i);
    }
    cout << d;
}
#define task "DAYCON"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    pre.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    subtask3();
    return 0;
}