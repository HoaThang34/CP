#include <bits/stdc++.h>
using namespace std;
long long n;
long long v, a;
vector<long long> arr;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> v >> a;
        for(int j = 1; j <= a; j++){
            arr.push_back(v);
        }
        sort(arr.begin(),arr.end());
        long long mid = (arr.size() - 1) / 2;
        cout << arr[mid] << endl;
    }
    return 0;
}