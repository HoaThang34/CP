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
		long long n;
		string s;
		cin>>n>>s;
		vector<long long> pa,pb;
		for(int i=0; i<(int)n; i++) {
			if(s[i]=='a') pa.push_back(i+1);
			else pb.push_back(i+1);
		}
		auto calc=[&](vector<long long>&p)->long long{
			long long k=(long long)p.size();
			if(k<=1) return 0;
			vector<long long> b(k);
			for(int i=0; i<(int)k; i++) b[i]=p[i]-i;
			long long m=b[k/2];
			long long r=0;
			for(int i=0; i<(int)k; i++) r += llabs(b[i]-m);
			return r;
		};
		long long ra=calc(pa);
		long long rb=calc(pb);
		cout<<min(ra,rb)<<endl;
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