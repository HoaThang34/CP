#include <bits/stdc++.h>
using namespace std;
map<long long, long long> memo;
long long power(int base, int exp){
    long long res = 1;
    for(int i = 0; i < exp; ++i) res *= base;
    return res;
}
long long sum_digits_up_to(long long n){
    if(n < 10){
        return n * (n + 1) / 2;
    }
    if(memo.count(n)){
        return memo[n];
    }
    string s = to_string(n);
    int len = s.length();
    long long p10 = power(10, len - 1);
    long long first_digit = n / p10;
    long long rem = n % p10;
    long long ans = 0;
    ans += (first_digit * (first_digit - 1) / 2) * p10;
    ans += first_digit * (rem + 1);
    ans += first_digit * sum_digits_up_to(p10 - 1);
    ans += sum_digits_up_to(rem);
    return memo[n] = ans;
}
void solve(){
    long long k;
    cin >> k;
    long long ans = 0;
    long long num_len = 1;
    long long count = 9;
    while(true){
        long long digits_in_block = num_len * count;
        if(k <= digits_in_block){
            break;
        }
        k -= digits_in_block;
        long long start_num = power(10, num_len - 1);
        long long end_num = power(10, num_len) - 1;
        ans += sum_digits_up_to(end_num) - sum_digits_up_to(start_num - 1);
        num_len++;
        count *= 10;
    }
    long long start_num = power(10, num_len - 1);
    long long full_nums_count = (k - 1) / num_len;
    long long end_num = start_num + full_nums_count - 1;
    if(full_nums_count > 0){
        ans += sum_digits_up_to(end_num) - sum_digits_up_to(start_num - 1);
    }
    long long leftover_digits = (k - 1) % num_len + 1;
    if(leftover_digits > 0){
        string last_num_str = to_string(end_num + 1);
        for(int i = 0; i < leftover_digits; ++i){
            ans += last_num_str[i] - '0';
        }
    }
    cout << ans << endl;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    memo[0] = 0;
    while(t--){
        solve();
    }
    return 0;
}