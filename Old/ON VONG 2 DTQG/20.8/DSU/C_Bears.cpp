#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void subtask1(){
    for (int x = 1; x <= n; x++){
        long long ans = 0;
        for (int i = 1; i <= n - x + 1; i++){
            long long rmax = -1;
            for (int j = i; j < i + x; j++){
                if (rmax == -1 || rmax > a[j]){
                    rmax = a[j];
                }
            }
            if (ans < rmax){
                ans = rmax;
            }
        }
        cout << ans << " ";
    }
}
void subtask2(){
    for (int x = 1; x <= n; x++){
        long long ans = 0;
        deque<long long> dq;
        for (int i = 1; i <= n; i++){
            while (!dq.empty() && a[dq.back()] >= a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - x){
                dq.pop_front();
            }
            if (i >= x){
                long long rmin = a[dq.front()];
                if (ans < rmin){
                    ans = rmin;
                }
            }
        }
        cout << ans << " ";
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
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }    
    // subtask1();
    subtask2();
    return 0;
}