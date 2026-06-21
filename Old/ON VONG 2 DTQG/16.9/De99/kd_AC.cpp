#include <bits/stdc++.h>
using namespace std;
// khai báo biến
#define task "kd"
long long n,k;
vector<long long> a;
namespace sub1{
    long long sum[1000001];
    bool check(){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]<0) cnt++;
        }
        return cnt<=1;
    }
    void sol(){
        int x=0;
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
            if(a[i]<0) x=i;
        }
        if(!x){
            cout<<sum[n];
            return;
        }
        long long s1=sum[x-1],s2=sum[n]-sum[x],s3=sum[n];
        if(s3>=s1+s2) cout<<s3;
        else if(k>=2) cout<<s1+s2;
        else cout<<max(s1,s2);
    }
}
namespace sub2{
    long long sum,maxsum;
    bool check(){
        return k==1;
    }
    void sol(){
        sum=maxsum=a[1];
        for(int i=2;i<=n;i++){
            if(sum<0) sum=0;
            sum+=a[i];
            maxsum=max(maxsum,sum);
        }
        cout<<maxsum;
    }
}
namespace sub345{
    long long f[2001][2001],g[2001][2001];
    bool check(){
        return 1;
    }
    void sol(){
        for(int i=1;i<=n;i++){
            f[i][0]=0;
            g[i][0]=LLONG_MIN/2;
        }
        for(int j=1;j<=k;j++){
            for(int i=1;i<=n;i++){
                g[i][j]=max(f[i-1][j-1],g[i-1][j])+a[i];
                f[i][j]=max(f[i-1][j],g[i][j]);
            }
        }
        cout<<f[n][k];
    }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n>>k;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(sub1::check()) sub1::sol();
    else if(sub2::check()) sub2::sol();
    else sub345::sol();
    return 0;
}
