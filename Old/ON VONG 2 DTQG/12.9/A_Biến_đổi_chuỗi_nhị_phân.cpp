#include <bits/stdc++.h>
using namespace std;
long long n;
string s, t;
long long cnt = 0;
void subtask1(){
    string s1 = s + t;
    for(char x : s1){
        if(x == '0') cnt++;
    }
    if(cnt % 2 != 0){
        cout << -1 << endl;
        return;
    }
    vector<long long> a, b;
    for(int i = 0; i < n; ++i){
        if(s[i] != t[i]){
            if(s[i] == '0'){
                a.push_back(i + 1);
            }
            else{
                b.push_back(i + 1);
            }
        }
    }
    vector<pair<long long, long long>> p;
    for(size_t i = 0; i + 1 < a.size(); i += 2){
        p.push_back({a[i], a[i+1]});
    }
    for(size_t i = 0; i + 1 < b.size(); i += 2){
        p.push_back({b[i], b[i+1]});
    }
    if(a.size() % 2 != 0){
        long long x = a.back();
        long long y = b.back();
        p.push_back({x, x});
        p.push_back({x, y});
    }
    cout << p.size() << endl;
    for(auto x : p){
        cout << x.first << " " << x.second << endl;
    }
}
#define task "bstr"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    cin >> s >> t;
    subtask1();
    return 0;
}
