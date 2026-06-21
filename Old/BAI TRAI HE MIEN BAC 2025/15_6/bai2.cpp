#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
#define task "noitu"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<string> f(n), l(n);
        for(int i=0;i<n;i++){
            cin>>f[i]>>l[i];
        }
        unordered_map<string, vector<int>> mp;
        mp.reserve(n*2);
        for(int i=0;i<n;i++){
            mp[f[i]].push_back(i);
        }
        vector<vector<int>> p(n);
        vector<int> deg(n);
        for(int i=0;i<n;i++){
            auto it = mp.find(l[i]);
            if(it!=mp.end()){
                deg[i] = it->second.size();
                for(int j: it->second){
                    p[j].push_back(i);
                }
            } else {
                deg[i] = 0;
            }
        }
        vector<int> st(n, 0), rem = deg;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0){
                st[i] = -1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            if(st[u] == -1){
                for(int p: p[u]){
                    if(st[p]==0){
                        st[p] = 1;
                        q.push(p);
                    }
                }
            } else if(st[u] == 1){
                for(int p: p[u]){
                    if(st[p] == 0){
                        rem[p]--;
                        if(rem[p] == 0){
                            st[p] = -1;
                            q.push(p);
                        }
                    }
                }
            }
        }
        bool qw=false, dr=false;
        for(int i=0;i<n;i++){
            if(deg[i] > 0 && st[i] == -1){
                qw = true;
                break;
            }
        }
        if(qw){
            cout<<"Quang\n";
            continue;
        }
        for(int i=0;i<n;i++){
            if(deg[i] > 0 && st[i] == 0){
                dr = true;
                break;
            }
        }
        if(dr){
            cout<<"Hoa\n";
        } else {
            cout<<"Hieu\n";
        }
    }
    return 0;
}
