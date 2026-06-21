/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "sodep"
int n;
bool check(int n){
    long long s = 0;
    while (n > 0){
        s += n % 10;
        n/=10;
    }
    string st = to_string(s);
    if (st[st.size() - 1] == '9'){
        return true;
    }
    return false;
}
void hoathang(){
    cin >> n;
    if (check(n)) cout << 1 << endl;
    else cout << 0 << endl;
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
