#include <bits/stdc++.h>
using namespace std;
#define task "sol"
long long m, n;
vector<long long> a, b;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> m >> n;
    a.resize(m + 1);
    b.resize(n + 1);
    for(int i = 1; i <= m; i++){
        cin>>a[i];
    }
    for(int j = 1; j <= n; j++){
        cin>>b[j];
    }
    vector<long long> ans;
    long long pos = 1;
    for(int i = 1; i <= m; i++){
        for(int j = pos; j <= n; j++){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                pos = j + 1;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}