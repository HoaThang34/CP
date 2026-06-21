#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    double r;
    cin >> r;
    
    const double PI = 3.14;
    
    double chu_vi = 2 * PI * r;
    double dien_tich = PI * r * r;
    
    cout << fixed << setprecision(3) << chu_vi << " " << dien_tich << endl;
    
    return 0;
}