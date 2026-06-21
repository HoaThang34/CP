/*
author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang() {
	long long t;
	if(!(cin>>t)) return;
	while(t--) {
		long long n,k,l,rr;
		cin>>n>>k>>l>>rr;
		vector<long long> a;
		a.resize(n+1);
		for(int i=1; i<=n; i++) cin>>a[i];
		std::function<long long(long long)> atmost = [&](long long K)->long long{
			if(K<0) return 0;
			unordered_map<long long,long long> mp;
			mp.reserve(1024);
			int rp=0;
			long long d=0;
			long long res=0;
			for(int L=1; L<=n; L++) {
				while(rp<n && (d + (mp.count(a[rp+1])==0?1:0) <= K)) {
					rp++;
					if(mp[a[rp]]==0) d++;
					mp[a[rp]]++;
				}
				long long low = L + l - 1;
				long long high = min((long long)rp, L + rr - 1);
				if(high >= low) res += (high - low + 1);
				unordered_map<long long,long long>::iterator it = mp.find(a[L]);
				if(it!=mp.end()) {
					if(it->second==1) {
						mp.erase(it);
						d--;
					} else it->second--;
				}
			}
			return res;
		};
		long long ans = atmost(k) - atmost(k-1);
		cout<<ans<<endl;
	}
}
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
