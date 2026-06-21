#include <bits/stdc++.h>
using namespace std;
long long n;
#define task "POSTERS"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    stack<long long> st;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        long long w, h;
        cin >> w >> h;
        while(!st.empty() && st.top() > h){
            st.pop();
        }
        if(st.empty() || st.top() < h){
            if(h > 0){
                ans++;
                st.push(h);
            }
        }
    }
    cout << ans;
    return 0;
}