// Fibonacci Number in O(logn * log logn) using divide and conquer

// f(n) = f(n)
// f(n+1) = f(n) + f(n-1)
// f(n+2) = f(n+1) + f(n) = f(n)*2 + f(n-1)
// f(n+3) = f(n+2) + f(n+1) = f(n)*3 + f(n-1)*2
// ...
// f(n+k) = f(n)*f(k+1) + f(n-1)*f(k)a
// f(2n+1) = f(n)*f(n+2) + f(n-1)*f(n+1)

// so if we know f(n) and f(n-1) we can calculate f(2n) and f(2n+1)

#include <map>
#include <iostream>
using namespace std;
#define long long long
const long M = 1000000007;
map<long, long> F;

long f(long n)
{
	if (F.count(n))
		return F[n];

	long k = n / 2;

	if (n % 2 == 0)
		return F[n] = (f(k) * f(k) + f(k - 1) * f(k - 1)) % M;
	else
		return F[n] = (f(k) * f(k + 1) + f(k - 1) * f(k)) % M;
}

int main()
{
	long n;
	F[0] = F[1] = 1;
	while (cin >> n)
		cout << (n == 0 ? 0 : f(n - 1)) << endl;
}