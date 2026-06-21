#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
string mul(string s,long long x){
    long long nho=0;
    string res="";
    for(int i=s.size()-1;i>=0;i--){
        long long t=(s[i]-'0')*x+nho;
        res.push_back(char(t%10+'0'));
        nho=t/10;
    }
    while(nho){
        res.push_back(char(nho%10+'0'));
        nho/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
string fact(long long x){
    string res="1";
    for(long long i=2;i<=x;i++)res=mul(res,i);
    return res;
}
string xuli(long long x){
    if(x==1)return "1";
    return fact(x-1);
}
#define task "bd"
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]*a[i]*a[i];
    }
    for(int i=1;i<=n;i++){
        cout<<xuli(a[i])<<'\n';
    }
    return 0;
}
