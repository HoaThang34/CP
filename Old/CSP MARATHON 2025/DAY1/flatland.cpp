#include <bits/stdc++.h>
using namespace std;
long long m, n;
vector <vector<long long>> a;
set <long long> s;
void subtask1(){
    long long rmax = 0;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            long long h = 1, w = 1;
            long long ans = 2 * (h + w);
            if (i + 1 <= m && j + 1 <= n &&
                a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]){
                h++; w++;
                ans += 2 * (h + w);
            }
            else if (i + 1 <= m && a[i][j] == a[i + 1][j]){
                w++;
                ans += 2 * (h + w);
            }
            else if (j + 1 <= n && a[i][j] == a[i][j + 1]){
                h++;
                ans += 2 * (h + w);
            }
            else break;
            rmax = max (rmax, ans);
        }
    }
    cout << rmax;
}
void subtask2(){
    long long rmax = 0;
    for (long long val : s){
        vector <long long> h(n + 1, 0);
        for (int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] == val) h[j]++;
                else h[j] = 0;
            }
            vector <long long> l(n + 1), r(n + 1);
            stack <long long> st;
            for (int j = 1; j <= n; j++){
                while (!st.empty() && h[st.top()] >= h[j]) st.pop();
                if (st.empty()){
                    l[j] = 1;
                }
                else l[j] = st.top() + 1;
                st.push(j);
            }
            while (!st.empty()) st.pop();
            for (int j = n; j >= 1; j--){
                while (!st.empty() && h[st.top()] >= h[j]) st.pop();
                if (st.empty()){
                    r[j] = n;
                }
                else r[j] = st.top() - 1;
                st.push(j);
            }
            for (int j = 1; j <= n; j++){
                if (h[j] > 0) {
                    long long w = r[j] - l[j] + 1;
                    long long h1 = h[j];
                    long long ans = 2 * (h1 + w);
                    rmax = max(rmax, ans);
                }
            }
        }
    }
    cout << rmax;
}
#define task "flatland"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> m >> n;
    a.resize(m + 1, vector <long long> (n + 1));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            s.insert(a[i][j]);
        }
    }
//    subtask1();
    subtask2();
    return 0;
}
