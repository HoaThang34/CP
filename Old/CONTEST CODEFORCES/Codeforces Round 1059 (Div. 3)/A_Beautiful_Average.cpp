#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
long long n;
vector<long long> a;
void hoathang() {
	cin>>n;
	a.resize(n+1);
	long long m=LLONG_MIN;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>m) m=a[i];
	}
	cout<<m<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if(fopen(nap".inp","r")) {
		freopen(nap".inp","r",stdin);
		freopen(nap".out","w",stdout);
	}
	long long t=1;
	cin>>t;
	while(t--) {
		hoathang();
	}
	return 0;
}
