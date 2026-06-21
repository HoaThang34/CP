#include <bits/stdc++.h>
using namespace std;
long long n;
bool sodep(long long n){
    if (n % 3 == 0 || n % 5 == 0 || n % 7 == 0){
        return true;
    }
    return false;
}
void subtask1(){
    int d = 0;
    long long k = 0;
    while (d != n){
        k++;
        if (sodep(k)) d++;
    }
    cout << k;
}
void subtask2(){
    long long l = 1, r = 1e18;
    while (l < r) {
        long long mid = (l + r) / 2;
        long long a = mid / 3;
        long long b = mid / 5;
        long long c = mid / 7;
        long long ab = mid / (3 * 5);
        long long ac = mid / (3 * 7);
        long long bc = mid / (5 * 7);
        long long abc = mid / (3 * 5 * 7);
        long long cnt = a + b + c - ab - ac - bc + abc;
        if (cnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    subtask1();
    // subtask2();
    return 0;
}