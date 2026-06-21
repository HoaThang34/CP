#include <bits/stdc++.h>
using namespace std;
#define task "sol"

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    long long t; 
    cin >> t;
    while(t--){
        long long n, m; 
        cin >> n >> m;
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) cin >> a[i];

        vector<pair<int,int>> v;
        bool ok = false;
        int limitCheck = 200; // số lượng phần tử tối đa ghép thử với 1 số

        for(int i=1; i<=n && !ok; i++){
            for(int j=i+1; j<=min((int)n, i+limitCheck); j++){
                if(__gcd(a[i],a[j])==1){
                    v.push_back({i,j});
                    if(v.size()>=2){
                        for(int x=0; x<(int)v.size(); x++){
                            for(int y=x+1; y<(int)v.size(); y++){
                                if(v[x].first!=v[y].first && 
                                   v[x].first!=v[y].second && 
                                   v[x].second!=v[y].first && 
                                   v[x].second!=v[y].second){
                                    cout<<v[x].first<<" "<<v[x].second<<" "
                                        <<v[y].first<<" "<<v[y].second<<"\n";
                                    ok=true;
                                    break;
                                }
                            }
                            if(ok) break;
                        }
                    }
                }
            }
        }
        if(!ok) cout<<0<<"\n";
    }
    return 0;
}
