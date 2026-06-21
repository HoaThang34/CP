#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
map <long long, long long> mp;
void subtask1(){
    vector <pair<long long, long long>> ans;
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j <= n; j++){
            if (a[i] == a[j]){
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans){
        cout << x.first << ' ' << x.second << endl;
    }
}
void subtask2(){
    for (auto x : mp){
        if (x.second == 1 || x.second == 0){
            continue;
        }
        else{
            vector <long long> ans;
            for (int i = 1; i <= n; i++){
                if (a[i] == x.first){
                    ans.push_back(i);
                }
            }
            // for (long long k : ans){
            //     cerr << k << ' ';
            // }
            // cerr << endl;
            vector <pair<long long, long long>> res;
            long long len = ans.size();
            for (int i = 0; i < len; i++){
                // cerr << ans[i] << ' ';
                for (int j = i + 1; j < len; j++){
                    res.push_back({ans[i], ans[j]});
                    // cout << ans[i] << ' ' << ans[j] << endl; 
                }
            }
            cout << res.size() << endl;
            for (auto x : res){
                cout << x.first << ' ' << x.second << endl;
            }
        }
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
        mp[a[i]]++;
    }
    subtask1();
    // subtask2();

    return 0;
}