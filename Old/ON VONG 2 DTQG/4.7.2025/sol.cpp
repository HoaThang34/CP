#include <bits/stdc++.h>
using namespace std;
long long n, s;
vector <long long> a;
long long f[45][10005];
void subtask1(){
    f[0][0] = 1;
    for (long long i = 1; i <= n; i++){
        for (long long j = 0; j <= s; j++){
            f[i][j] = f[i - 1][j];
            if (j >= a[i]){
                f[i][j] += f[i-1][j-a[i]];
            }
        }
    }
    cout << f[n][s];
}
void gen(int i,int h,long long sm,vector<long long>& v){
    if(i>h){
        v.push_back(sm);
        return;
    }
    gen(i+1,h,sm,v);
    gen(i+1,h,sm+a[i],v);
}
void subtask2(){
    int m=n/2;
    vector<long long> L,R;
    gen(0,m-1,0,L);
    gen(m,n-1,0,R);
    sort(L.begin(),L.end());
    long long res=0;
    for(long long x:R){
        long long t=s-x;
        auto p=equal_range(L.begin(),L.end(),t);
        res+=p.second-p.first;
    }
    cout<<res;
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> s;
    a.resize(n + 1);
    for (long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    // subtask2();
    subtask1();
    return 0;
}
