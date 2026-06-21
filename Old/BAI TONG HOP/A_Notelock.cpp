/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

int t;
int n,k;
string s;

void hoathang(){
    cin>>n>>k>>s;
    int ans=0;
    int pos = -1e18;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            int p=i+1;
            if(p-pos>=k){
                ans++;
                pos=p;
            }else{
                pos=p;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    cin>>t;
    while(t--){
        hoathang();
    }
    return 0;
}
