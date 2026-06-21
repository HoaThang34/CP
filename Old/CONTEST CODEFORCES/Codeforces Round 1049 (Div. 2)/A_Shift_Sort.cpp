#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    if(s == sorted_s){
        cout << 0 << '\n';
        return;
    }
    queue<pair<string, int>> q;
    q.push({s, 0});
    set<string> visited;
    visited.insert(s);
    while(!q.empty()){
        string u = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(u == sorted_s){
            cout << steps << '\n';
            return;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    string v_right = u;
                    char temp = v_right[i];
                    v_right[i] = v_right[k];
                    v_right[k] = v_right[j];
                    v_right[j] = temp;
                    if(visited.find(v_right) == visited.end()){
                        visited.insert(v_right);
                        q.push({v_right, steps + 1});
                    }
                    string v_left = u;
                    temp = v_left[i];
                    v_left[i] = v_left[j];
                    v_left[j] = v_left[k];
                    v_left[k] = temp;
                    if(visited.find(v_left) == visited.end()){
                        visited.insert(v_left);
                        q.push({v_left, steps + 1});
                    }
                }
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
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}