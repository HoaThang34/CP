/*
author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long t,n,L,R,mid;
vector<long long> a;
void hoathang() {
	cin>>t;
	while(t--) {
		cin>>n;
		a.resize(n+1);
		for(int i=1; i<=n; i++) cin>>a[i];
		sort(a.begin()+1,a.end());
		L=0;
		R=a[n]-a[1];
		while(L<R) {
			mid=(L+R)/2;
			int cnt=0;
			for(int i=1; i<=n-1;) {
				if(a[i+1]-a[i]<=mid) {
					cnt++;
					i+=2;
				}
				else i++;
			}
			if(cnt>=n/2) R=mid;
			else L=mid+1;
		}
		cout<<L<<endl;
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