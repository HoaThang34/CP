#include <bits/stdc++.h>
using namespace std;

const int INF = 2000000007; 

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    long long k; 
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    if (n < 2){ 
        return 0; 
    }

    vector<int> v; 

    for (int l = 0; l < n; ++l){
        for (int r = l + 1; r < n; ++r){ 
            int cur_xor = INF;
            for (int i = l; i <= r; ++i){
                for (int j = i + 1; j <= r; ++j){
                    cur_xor = min(cur_xor, a[i] ^ a[j]);
                }
            }
            if (cur_xor != INF){
                 v.push_back(cur_xor);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    if (k > 0 && k <= (long long)v.size()){ 
         cout << v[k - 1] << endl;
    }

    return 0;
}