#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int n)
{
 if (n < 2) return false;
 for (int i = 2; i * i <= n; ++i)
 {
 if (n % i == 0) return false;
 }
 return true;
}
int kiemtra(int n)
{
 int s = 0;
 while (n > 0)
 {
 int d = n % 10;
 s += d * d;
 n /= 10;
 }
  return s;
}
int main()
{
 int A, B;
 cin >> A >> B;
 int res = 0;
 for (int i = A; i <= B; ++i)
 {
 if (is_prime(i) && is_prime(kiemtra(i)))
 {
 res++;
 }
 }
 cout << res;
 return 0;
}