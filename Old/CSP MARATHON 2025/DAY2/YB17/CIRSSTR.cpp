#include <bits/stdc++.h>
using namespace std;
string s, s1;
void subtask1(){
    s += s;
    s1 += s1;
    long long rmax = 0;
    for (int i = 0; i < s.size() / 2; i++){
        for (int j = 0; j < s1.size() / 2; j++){
            long long d = 0;
            int i1 = i, j1 = j;
            while (i1 < i + s.size() / 2 && j1 < j + s1.size() / 2 && s[i1] == s1[j1]){
                d++;
                i1++;
                j1++;
            }
            rmax = max(rmax, d);
        }
    }
    cout << rmax;
}
#define task "CIRSSTR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> s >> s1;
    subtask1();
    return 0;
}