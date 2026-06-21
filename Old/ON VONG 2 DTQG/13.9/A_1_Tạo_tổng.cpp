#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
void subtask1(){
    set <long long> st;
    st.insert(0);
    for (int i = 1; i <= n; i++){
        vector <long long> tmp;
        for (long long x : st){
            long long s = x + a[i];
            tmp.push_back(s);
        }
        for (long long x : tmp){
            st.insert(x);
        }
    }
    cout << st.size() << '\n';
    for (long long x : st){
        cout << x << ' ';
    }
}
#define task ""
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
    subtask1();
    return 0;
}