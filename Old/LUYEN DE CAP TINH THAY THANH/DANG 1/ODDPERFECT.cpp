///*
//    author: hoaquangthang
//*/
//#include <bits/stdc++.h>
//using namespace std;
//const long long N = 1e6 + 5;
//#define endl '\n'
//#define nap "ODDPERFECT"
//long long l, r;
//vector<long long> f;
//void hoathang(){
//    cin >> l >> r;
//    f.resize(N, 0);
//    for (long long i = 1; i <= N; i++){
//        for (long long j = i; j <= N; j+=i){
//            f[j] += i;
//        }
//    }
//    vector<long long> ans;
//    long long d = 0;
//    for (long long i = l; i <= r; i++){
//        if (f[i] - i ==  i){
//            ans.push_back(i);
//        }
//    }
//    if (ans.size() == 0) cout << "None" << endl;
//    else for (long long x : ans) cout << x << ' ';
//}
//
//signed main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    if (fopen(nap".inp", "r")){
//        freopen(nap".inp", "r", stdin);
//        freopen(nap".out", "w", stdout);
//    }
//    hoathang();
//    return 0;
//}


/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang(){
    long long L, R;
    if (!(cin >> L >> R)) return;
    vector<long long> p = {
        6LL,
        28LL,
        496LL,
        8128LL,
        33550336LL,
        8589869056LL,
        137438691328LL
    };
    bool ok = false;
    for (long long x : p) {
        if (x >= L && x <= R) {
            cout << x << " ";
            ok = true;
        }
    }
    if (!ok) cout << "None";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
