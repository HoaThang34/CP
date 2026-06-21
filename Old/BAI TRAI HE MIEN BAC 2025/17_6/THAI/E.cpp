#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"
int n;
ll a[100005], mx=0;
vector<int> kq, t;
void dq(int i, ll s){
    if(i>n){
        if(s>mx || (s==mx && t<kq)){
            mx=s;
            kq=t;
        }
        return;
    }
    dq(i+1, s);
    t.push_back(i);
    dq(i+2, s + a[i]);
    t.pop_back();
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)  
        cin>>a[i];
    dq(1, 0);
    cout<<mx<<"\n"<<kq.size()<<"\n";
    for(int i=0;i<kq.size();i++){
        cout<<kq[i]<<(i+1<kq.size()?" ":"");
    }
    return 0;
}
