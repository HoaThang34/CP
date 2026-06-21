#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
vector <long long> a;
const long long N = 1e5 / 2 + 1;
void sub1(){
    long long sum = 0;
    vector <bool> check(n + 1, true);
    for (int i = 1; i <= n; i++){
        sum+=a[i];
        bitset <N> dp;
        dp.reset();
        dp[0] = 1;
        long long s = 0;
        for (int j = i; j <= n; j++){
            s+=a[j];
            dp|= (dp << a[j]);
            bool check1 = true;
            if (s % 2 != 0 || s/2 >= dp.size() || !dp[s/2]){
                    check1 = false;
            }
            if (!check1){
                check[j - i + 1] = false;
            }

        }
    }
    vector <long long> res;
    for(int k=1;k<=n;k++) if(check[k]) res.push_back(k);
    cout<<res.size();
    for(int k:res) cout << " " << k;
    cout<< endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
       sub1();
    }
    return 0;
}