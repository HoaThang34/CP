#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;
int n, m;
char R[105][105], D[105][105];
bool vs[105][105];
bool check(char x, int mk){
    if(x == 'P' && ((mk >> 0) & 1)) return true;
    if(x == 'C' && ((mk >> 1) & 1)) return true;
    if(x == 'Z' && ((mk >> 2) & 1)) return true;
    if(x == 'N' && ((mk >> 3) & 1)) return true;
    return false;
}
bool in(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
#define task "DYNAMITE"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            cin >> R[i][j];
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            cin >> D[i][j];
        }
    }
    int q; cin >> q;
    while(q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        int res = 4;
        for(int mk=0; mk<(1<<4); mk++){
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vs[i][j] = false;
            queue<pair<int,int>> qu;
            qu.push({x, y});
            while(!qu.empty()){
                int cx = qu.front().first, cy = qu.front().second;
                qu.pop();
                if(vs[cx][cy]) continue;
                vs[cx][cy] = true;
                if(in(cx+1, cy) && !vs[cx+1][cy] && check(D[cx][cy], mk)) qu.push({cx+1, cy});
                if(in(cx-1, cy) && !vs[cx-1][cy] && check(D[cx-1][cy], mk)) qu.push({cx-1, cy});
                if(in(cx, cy+1) && !vs[cx][cy+1] && check(R[cx][cy], mk)) qu.push({cx, cy+1});
                if(in(cx, cy-1) && !vs[cx][cy-1] && check(R[cx][cy-1], mk)) qu.push({cx, cy-1});
            }
            if(vs[u][v]){
                int c=0;
                for(int b=0;b<4;b++) if((mk>>b)&1) c++;
                if(c < res) res = c;
            }
        }
        cout << res << '\n';
    }
    return 0;
}