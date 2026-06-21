#include <bits/stdc++.h>
using namespace std;
int main()
{
 int N;
 cin >> N;
 vector<int> a(N);
 for (int i = 0; i < N; ++i) cin >> a[i];
 sort(a.begin(), a.end(), greater<int>());
 long long res = 0;
 for (int i = 0; i < N; ++i)
 if ((i + 1) % 3 != 0)
 res += a[i];
 cout << res;
 return 0;
}