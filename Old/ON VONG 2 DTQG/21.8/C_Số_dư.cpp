#include <bits/stdc++.h>
using namespace std;
long long a, b;
void subtask1(){
    long long r = 0;
    while ((a - r) % b != 0){
        r++;
    }
    cout << r;
}
void subtask2(){
    cout << a % b;
}
#define task "remainder"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> a >> b;
    // subtask1();
    // subtask2();
    if (a <= 1000000 && b <= 1000000){
        subtask1();
    }
    else{
        subtask2();
    }
    return 0;
}