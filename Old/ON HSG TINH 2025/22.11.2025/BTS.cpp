/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "BTS"

long long n;
vector<int> a;
long long ans;

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ans = 0;
    stack<long long> st;
    for (int i = 1; i <= n; i++){
        while (!st.empty() && a[st.top()] <= a[i]){
            st.pop();
            ans++;
        }
        if (!st.empty()){
            ans++;
        }
        st.push(i);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".INP", "r")){
        freopen(nap".INP", "r", stdin);
        freopen(nap".OUT", "w", stdout);
    }
    hoathang();
    return 0;
}
