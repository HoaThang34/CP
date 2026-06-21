/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "ATM"
int n, m;
vector<int> a;
void hoathang(){
    cin >>  n>> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> sum;
    sum.push_back(0);
    for (int i = 1; i <= n; i++){
        int sz = sum.size();
        for (int j = 0; j < sz; j++){
            sum.push_back(sum[j] + a[i]);
        }
    }
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    int d = 0;
    while (m--){
        long long s;
        cin >> s;
        if (binary_search(sum.begin(), sum.end(), s)){
            d++;
        }
    }
    cout << d << endl;
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
