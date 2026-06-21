#include <bits/stdc++.h>
using namespace std;

#define task ""
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        if(i == 1 || i == n)
        {
            for(int j = 1; j <= m; j++)
            cout << "#";
        }
        else
        {
            for(int j = 1; j <= m; j++)
            {
                if(j == 1 || j == m)
                cout << "#";
                else
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}