#include <bits/stdc++.h>
using namespace std;
long long t, a, b, d, s;
vector <long long> ans(1000005, 0);
vector <long long> ans1(1000005, 0);
vector <bool> f(1000005, true);
void sang(){
    f[0] = f[1] = false;
    for (long long i = 2; i <= 1000005; i++){
        if (f[i]){
            for (long long j = i * i; j <= 1000005; j += i){
                f[j] = false;
            }
        }
    }
}
long long rev(long long n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoll(s);
}
bool check(long long n){
    long long k = rev(n);
    if (n != k && f[k] && f[n]){
        return true;
    }
    else return false;
}
void subtask1(){
    d = 0;
    s = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (f[i]) s+=i;
        if (check(i)) d++;
    }
    cout << s << ' ' << d << endl;
}
void subtask2(){
    d = 0;
    s = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++){
        if (f[i]) s+=i;
        if (ans[i] == 1){
            d++;
        }
        else if (check(i) && ans[i] == 0){
            ans[i] = 1;
            d++;
        }
        else if (ans[i] == 3){
            continue;
        }
        else if (!check(i)){
            ans[i] = 3;
        }
    }
    cout << s << ' ' << d << endl;
}

#define task "twins"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    sang();
    cin >> t;
    if (t == 1){
        subtask1();
        return 0;
    }
    while (t--){
        subtask2();
    }
    return 0;
}