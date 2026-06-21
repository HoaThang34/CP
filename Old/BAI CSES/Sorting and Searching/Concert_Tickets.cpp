#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> h, t;
void subtask1(){
    for(int i = 1; i <= m; i++){
        long long ans = -1, pos = -1;
        for(int j = 1; j <= n; j++){
            if(h[j] != -1 && h[j] <= t[i]){
                if(ans == -1 || h[j] > ans){
                    ans = h[j];
                    pos = j;
                }
            }
        }
        if(ans == -1){
            cout << -1 << endl;
        } else{
            cout << ans << endl;
            h[pos] = -1;
        }
    }
}
void subtask2(){
    sort(h.begin() + 1, h.end());
    for(int i = 1; i <= m; i++){
        int l = 1, r = h.size() - 1, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(h[mid] != -1 && h[mid] <= t[i]){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(ans == -1){
            cout << -1 << endl;
        } else{
            cout << h[ans] << endl;
            h[ans] = -1;
        }
    }
}
#define task "Concert_Tickets"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    h.resize(n + 1);
    t.resize(m + 1);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> t[i];
    }
    // subtask1();
    subtask2();
    // if (n <= 200000 && m <= 200000){
    //     subtask1();
    // }
    // else subtask2();
    return 0;
}