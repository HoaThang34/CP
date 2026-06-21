/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long q;
    cin >> q;
    multiset<long long> ms;
    while(q--){
        char c;cin>>c;
        if(c=='?'){
            if(ms.empty()){
                cout<< -1<<' '<< -1<<' '<< -1<<' '<< -1<< endl;
                continue;
            }
            long long s1=*ms.begin();
            long long s2=-1;
            if(ms.size()>=2) s2=*next(ms.begin());
            long long m1=*ms.rbegin();
            long long m2=-1;
            if(ms.size()>=2) m2=*next(ms.rbegin());
            cout<<s1<<' '<<s2<<' '<<m1<<' '<<m2<<endl;
        }
        else{
            long long x;cin>>x;
            if(c=='+') ms.insert(x);
            else{ 
                if(ms.find(x)!=ms.end()){
                    ms.erase(ms.find(x));
                }
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    while (t--){
        hoathang();
    }
    return 0;
}
