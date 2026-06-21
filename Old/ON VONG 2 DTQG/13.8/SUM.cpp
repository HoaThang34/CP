#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
long long ans = 0;
void subtask1(){
    ans = 0;
    for (int i = a; i <= b; i++){
        ans += (n/i);
    }
    cout << ans;
}
void subtask3(){
    long long sochia = a;
    ans = 0;
    while (sochia <= b){
        long long thuong = n / sochia;
        if (thuong == 0) break;                 
        long long dem = n / thuong;
        if (dem > b) dem = b;                    
        ans += thuong * (dem - sochia + 1);      
        sochia = dem + 1;                        
    }
    cout << ans;
}
#define task "SUM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> a >> b;
    // subtask1();
    // subtask2();
    // subtask3();
    if (a == 1 && b == n){
        if (n <= 1000000){
            subtask1();
            return 0;
        }
        else{
            subtask3();
            return 0;
        }
    }
    else{
        subtask3();
        return 0;
    }
    return 0;
}