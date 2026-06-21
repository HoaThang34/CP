#include <bits/stdc++.h>
using namespace std;
long long n, a;
vector <long long> arr;
vector <pair<char, long long>> p;
#define task "NEAREST"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> a;
    arr.resize(n);
    // p.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    long long sum = arr[0];
    for (int i = 1; i < n; i++){
        if (sum <= a && arr[i] > 0){
            p.push_back({'+', arr[i]});
            sum += arr[i];
        }
        else if (sum <= a && arr[i] < 0){
            p.push_back({'+', arr[i]});
            sum -= arr[i];
        }
        else if (sum > a && arr[i] > 0){
            p.push_back({'-', arr[i]});
            sum -= arr[i];
        }
        else if (sum > a && arr[i] < 0){
            p.push_back({'+', arr[i]});
            sum += arr[i];
        }
    }
    cout << sum << endl;
    cout << arr[0];
    for (auto x : p){
        cout << x.first << x.second;
    }
    // for (long long x : arr) cout << x << ' ';
    return 0;
}