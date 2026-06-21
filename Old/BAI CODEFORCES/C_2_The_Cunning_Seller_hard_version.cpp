#include <bits/stdc++.h>
using namespace std;
const int MAX_X = 40;
vector<long long> p3(MAX_X);
vector<long long> cost(MAX_X);
void precompute(){
    p3[0] = 1;
    for(int i = 1; i < MAX_X; ++i){
        if(p3[i-1] > LLONG_MAX / 3) break;
        p3[i] = p3[i-1] * 3;
    }
    cost[0] = 3;
    for(int i = 1; i < MAX_X; ++i){
        if (p3[i] == 0 || p3[i-1] == 0 || i + 1 >= MAX_X || p3[i+1] == 0) break;
        cost[i] = p3[i+1] + (long long)i * p3[i-1];
    }
}
void solve(){
    long long n, k;
    cin >> n >> k;
    vector<long long> d(MAX_X, 0);
    long long min_deals = 0;
    long long current_cost = 0;
    long long temp_n = n;
    int max_i = 0;
    for(int i = 0; i < MAX_X && temp_n > 0; ++i){
        d[i] = temp_n % 3;
        min_deals += d[i];
        if(cost[i] > 0){
             current_cost += d[i] * cost[i];
        }
        temp_n /= 3;
        if(d[i] > 0){
            max_i = i;
        }
    }
    if(min_deals > k){
        cout << -1 << endl;
        return;
    }
    for(int i = max_i; i >= 0; --i){
        if(d[i+1] > 0){
            long long deals_to_add = k - min_deals;
            if(deals_to_add <= 0) break;
            long long num_breaks_possible = deals_to_add / 2;
            long long num_to_break = min(num_breaks_possible, d[i+1]);
            if(num_to_break > 0){
                long long cost_saving_per_break = cost[i+1] - 3 * cost[i];
                current_cost -= num_to_break * cost_saving_per_break;
                min_deals += num_to_break * 2;
                d[i+1] -= num_to_break;
                d[i] += num_to_break * 3;
            }
        }
    }
    cout << current_cost << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    precompute();
    long long t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}