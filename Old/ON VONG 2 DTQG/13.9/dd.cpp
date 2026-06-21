#include <bits/stdc++.h>
using namespace std;
long long n, x;
vector <long long> a;
bool check(vector <long long>& b, long long x, long long k){
    if (b[(k + 1) / 2] >= x){
        return true;
    }
    return false;
}
void subtask2(){ // n<=10^3
    int d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            vector <long long> b;
            for (int k = i; k <= j; k++){
                b.push_back(a[k]);
                // d++;
            }
            sort(b.begin(), b.end());
            if (check(b, x, b.size() - 1)){
                // for (long long x : b){
                //     cerr << x << ' ';
                // }
                // cerr << endl;
                d++;
            }
        }
    }
    cout << d;
}
void subtask1(){ // n <= 10^5, ai >=x;
    long long d = n * (n + 1) / 2;
    cout << d;
}
void subtask3(){ // n <= 10^5;
    int d = 0;
    for (int i = 1; i <= n; i++){
        vector <long long> b;
        for (int j = i; j <= n; j++){
            b.push_back(a[j]);
            sort(b.begin(), b.end());
            if (check(b, x, b.size() - 1)){
                d++;
            }
        }
    }
    cout << d;
}
void subtask4(){
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        long long d = 0;
        for (int j = i; j <= n; j++){
            if (a[j] >= x){
                d++;
            }
            long long l = j - i + 1;
            long long k = (l + 1) / 2;
            if (d >= k){
                ans++;
            }
        }
    }
    cout << ans;
}
#define task "dd"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> x;
    long long rmin = LLONG_MIN;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        rmin = min(rmin, a[i]);
    }
    // subtask2();
    // subtask1();
    // subtask3();
    // if (rmin >= x){
    //     subtask1();
    // }
    // else{
    //     // if (n <= 1e3){
    //     //     subtask2();
    //     // }
    //     // else{
    //     //     subtask3();
    //     // }
    //     subtask3();
    // }
    // subtask4();
    if (n <= 1e4 + 1e4 + 1e4){
        subtask4();
    }
    else{
        subtask1();
    }
    return 0;
}