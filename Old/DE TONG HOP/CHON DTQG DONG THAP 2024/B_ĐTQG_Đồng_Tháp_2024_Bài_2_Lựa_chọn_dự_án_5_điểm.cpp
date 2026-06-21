#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a, b;

bool cmp(const pair<long long, long long>& p1, const pair<long long, long long>& p2){
    return p1.first * p2.second < p2.first * p1.second;
}
long long xuli(const vector<pair<long long, long long>>& ps){
    if(n == 0){
        return 0;
    }
    vector<pair<long long, long long>> ans;
    ans.push_back(ps[0]);
    for(int i = 1; i < n; i++){
        if(cmp(ans.back(), ps[i])){
            ans.push_back(ps[i]);
        }
        else{
            auto it = lower_bound(ans.begin(), ans.end(), ps[i], cmp);
            *it = ps[i];
        }
    }
    return ans.size();
}

#define task "bai2"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector <pair <long long, long long>> ps(n);
    for (int i = 1; i <= n; i++){
        ps[i - 1].first = a[i];
        ps[i - 1].second = b[i];
    }
    cout << xuli(ps);
    return 0;
}