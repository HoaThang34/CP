/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

int ans = 1;

void subtask1(const string& s, int& res){
    int n = s.size();
    for (int l = 0; l < n; l++){
        int cnt[26] = {0}, mx = 0;
        for (int r = l; r < n; ++r){
            int id = s[r] - 'a';
            mx = max(mx, ++cnt[id]);
            int len = r - l + 1;
            if (mx * 2 > len) res = max(res, len);
        }
    }
}

void subtask2(const string& s, int& res){
    int n = s.size();
    for (int l = 0; l < n; l++){
        int cnt[26] = {0}, mx = 0;
        for (int r = l; r < n; ++r){
            int id = s[r] - 'a';
            mx = max(mx, ++cnt[id]);
            int len = r - l + 1;
            if (mx * 2 > len) res = max(res, len);
        }
    }
}

int xuli(const string& s, char c){
    int n = s.size();
    vector<int> f(n+1,0);
    for (int i = 0; i < n; i++) f[i+1] = f[i] + (s[i]==c ? 1 : -1);
    vector<int> st; st.reserve(n+1);
    for (int i = 0; i <= n; i++){
        if (st.empty() || f[i] < f[st.back()]) st.push_back(i);
    }
    int res = 0;
    for (int j = n; j >= 0; j--){
        while (!st.empty() && f[j] > f[st.back()]){
            res = max(res, j - st.back());
            st.pop_back();
        }
    }
    return res;
}

void subtask3(const string& s, int& res){
    int ans = 1;
    for (char c = 'a'; c <= 'z'; ++c){
        ans = max(ans, xuli(s, c));
    }
    ans = max(ans, res);
}

void hoathang(){
    string s; 
    cin >> s;
    int n = s.size();
    if (n <= 300) subtask1(s, ans);
    else if (n <= 5000) subtask2(s, ans);
    else subtask3(s, ans);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    while (t--){
        hoathang();
    }
    return 0;
}
