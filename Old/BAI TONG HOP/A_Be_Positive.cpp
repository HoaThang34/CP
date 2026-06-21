/*
author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long t,n,neg,z;
vector<long long> a;
void hoathang() {
	cin>>t;
	while(t--) {
		cin>>n;
		a.resize(n+1);
		neg=0;
		z=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			if(a[i]==-1) neg++;
			if(a[i]==0) z++;
		}
		long long ans = z + (neg%2)*2;
		cout<<ans<<endl;
	}
}
#define nap ""
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (fopen(nap".inp", "r")) {
		freopen(nap".inp", "r", stdin);
		freopen(nap".out", "w", stdout);
	}
	hoathang();
	return 0;
}