/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "hoathang"

void hoathang(){
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    bool all_neg = true;
    int max_val = -2e9;
    long long sum_all = 0;

    for(int i=0; i<n; ++i){
        cin >> a[i];
        if (a[i] >= 0) all_neg = false;
        max_val = max(max_val, a[i]);
        sum_all += a[i];
    }

    if (all_neg) {
        cout << max_val;
        return;
    }

    // Kadane max
    long long max_kadane = -1e18, current_max = 0;
    for(int x : a){
        current_max += x;
        if (current_max < 0) current_max = 0;
        max_kadane = max(max_kadane, current_max);
    }
    
    // Kadane min
    long long min_kadane = 1e18, current_min = 0;
    for(int x : a){
        current_min += x;
        if (current_min > 0) current_min = 0;
        min_kadane = min(min_kadane, current_min);
    }

    long long max_circular = sum_all - min_kadane;
    
    // If circular sum equals 0 (due to removing everything), avoid if necessary,
    // but handled by all_neg check. If not all negative, max_circular valid.
    /* 
       Actually if sum_all == min_kadane, max_circular is 0.
       If array 1 -10 1, sum = -8. min_subarray = -10.
       max_circular = -8 - (-10) = 2. Correct (1+1).
       
       If array -5 -5, handled by all_neg.
    */
    
    cout << max(max_kadane, max_circular);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
