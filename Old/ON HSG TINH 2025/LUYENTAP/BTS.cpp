#include <bits/stdc++.h>
#define maxn 1000005
#define Task "bts"
using namespace std;
typedef long long ll;
int n, a[maxn];
int q[maxn];
int loop = 0;
int Calc(){
    int cnt = 0;
    int top = 0;
    for (int i = 1; i <= n; i++){
        while (top > 0 && a[i] > q[top]){
            cnt++;
            top --;
        }
        if (top) cnt++;
        if (a[i] != q[top]) q[++top] = a[i];
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = Calc();
    cout << res;
    return 0;
}
