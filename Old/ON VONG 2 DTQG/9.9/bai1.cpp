#include <bits/stdc++.h>
using namespace std;
long long n;
vector <pair<long long, long long>> a;
void subtask1(){ // y = 0;
    long long ans = LLONG_MAX;
    long long ans1 = 0;
    for (int i = 1; i <= n; i++){
        long long sum = 0;
        for (int j = 1; j <= n; j++){
            sum += abs(a[i].first - a[j].first);
        }
        if (sum < ans){
            ans = sum;
            ans1 = i;
        }
    }
    cout << a[ans1].first << ' ' << a[ans1].second;
}
void subtask2(){ // y = 0;
    long long ans = LLONG_MAX;
    long long ans1 = 0;
    vector<long long> x(n + 1);
    for (int i = 1; i <= n; i++) {
        x[i] = a[i].first;
    }
    sort(x.begin(), x.end());
    long long mid = x[(n / 2) + 1];
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += abs(a[i].first - mid);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i].first == mid) {
            cout << a[i].first << ' ' << a[i].second;
            break;
        }
    }
}
void subtask3(){ // y != 0;
    long long ans = LLONG_MAX;
    long long ans1 = 0;
    for (int i = 1; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
        }
        if (sum < ans) {
            ans = sum;
            ans1 = i;
        }
    }
    cout << a[ans1].first << ' ' << a[ans1].second;
}
void subtask4(){
    vector<long long> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        x[i] = a[i].first;
        y[i] = a[i].second;
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    long long mid1 = x[(n + 1) / 2];
    long long mid2 = y[(n + 1) / 2];
    for (int i = 1; i <= n; i++) {
        if (a[i].first == mid1 && a[i].second == mid2) {
            cout << a[i].first << ' ' << a[i].second;
            return;
        }
    }
    cout << mid1 << ' ' << mid2;
}
#define task "dt"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    bool checksub = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        if (a[i].second != 0){
            checksub = false;
        }
    }    
    // subtask1();
    // subtask2();
    // subtask3();
    // subtask4();
    if (checksub){
        if (n <= 1000){
            subtask1();
        }
        else if (n <= 100000){
            subtask2();
        }
    }
    else{
        if (n <= 100){
            subtask3();
        }
        else{
            subtask4();
        }
    }
    return 0;
}
