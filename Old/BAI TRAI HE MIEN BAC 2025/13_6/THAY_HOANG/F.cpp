#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    a.resize(n + 1);
    for (long long i = 1; i <= n; i++){
        cin >> a[i];

    }
    long long res = 0;
    for (long long i = 1; i <= n; i++){
        long long cnt = 0;
        res++;
        for (long long j = i + 1; j <= n; j++){
            if (a[j] > a[i]) cnt++;
            else cnt--;
            if ((i - j) % 2 == 0 && cnt == 0){
                res++;
    
            }
            if (abs(cnt) > (n-j)) break;
        }
    }
    cout << res << endl;
    return 0;
}