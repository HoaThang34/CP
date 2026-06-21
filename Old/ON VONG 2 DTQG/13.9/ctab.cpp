#include <bits/stdc++.h>
using namespace std;
long long n;
vector <vector <long long> a, b;
vector<vector<long long>>doiHang(vector<vector<long long>>x,int h){
    for(int j=1;j<=n;j++){
        if(x[h][j]==1) x[h][j]=-1;
        else if(x[h][j]==-1) x[h][j]=1;
    }
    return x;
}
vector<vector<long long>>doiCot(vector<vector<long long>>x,int c){
    for(int i=1;i<=n;i++){
        if(x[i][c]==1) x[i][c]=-1;
        else if(x[i][c]==-1) x[i][c]=1;
    }
    return x;
}
#define task "ctab"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1, vector <long long> (n + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    b.resize(n + 1, vector <long long> (n + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> b[i][j];
        }
    }
    return 0;
}