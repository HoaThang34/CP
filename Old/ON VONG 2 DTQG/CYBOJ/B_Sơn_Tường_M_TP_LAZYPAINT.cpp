#include <bits/stdc++.h>
using namespace std;
struct Result{
    long long area;
    long long strokes;
};
bool is_better(const Result& a, const Result& b){
    if(a.area != b.area){
        return a.area < b.area;
    }
    return a.strokes < b.strokes;
}
long long n, x;
vector<long long> h, s;
vector<Result> dp;
#define task "LAZYPAINT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> x;
    h.resize(n + 1, 0);
    s.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        s[i] = s[i - 1] + h[i];
    }
    dp.resize(n + 1, {LLONG_MAX, LLONG_MAX});
    dp[0] = {0, 0};
    for(int i = 1; i <= n; i++){
        dp[i] = {dp[i - 1].area + h[i], dp[i - 1].strokes};
        for(long long j = i; j >= 1 && j >= i - x + 1; j--){
            long long start_roller = j;
            long long end_roller = j + x - 1;
            long long min_h_stroke = h[start_roller];
            for(long long k = start_roller + 1; k <= end_roller; k++){
                if (k > n){
                    break;
                }
                min_h_stroke = min(min_h_stroke, h[k]);
            }
            long long total_area_on_ji = s[i] - s[j - 1];
            long long roller_area_on_ji = (i - j + 1) * min_h_stroke;
            long long brush_cost_on_ji = total_area_on_ji - roller_area_on_ji;
            if(j > 0){
                Result candidate = {dp[j - 1].area + brush_cost_on_ji, dp[j - 1].strokes + 1};
                if(is_better(candidate, dp[i])){
                    dp[i] = candidate;
                }
            }
        }
    }
    cout << dp[n].area << endl;
    cout << dp[n].strokes << endl;
    return 0;
}