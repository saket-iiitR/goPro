// Number of numbers between 1 to n which are
// divisible by any of the prime numbers less than 20.

// Example: How many numbers less than 1000 and divisible by 2, 3, 5

// n = 3
// A = floor{999/2}
// B = floor{999/3}
// C = floor{999/5}
// |A n B| = floor{1000/(2*3)}
// |A n C| = floor{1000/(2*5)}
// |B n C| = floor{1000/(3*5)}
// |A n B n C| =  floor{1000/(2*3*5)}
// A u B = |A| + |B| + |C| - |A n B| - |A n C| + |B n C| + |A n B n C| = 733

// A u B u ..... N : =
// ( A + B + C + ...N ) Odd numbers positive
// - ( |A n B| + |A n C| ......) Even numbers negative
// + (|A n B n C| + .........) Odd numbers positive3
// - (|A n B n C n D| .......) Even numbers negative
// ...
// ...
// ...
// ...


#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	int n;
	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		// 8 primes : 2^8 = 256 subsets - 1 empty subset
		int subsets = (1 << 8) - 1;
		int ans = 0;
		for (int i = 1; i <= subsets; i++) {
			int denom = 1;
			int setBits = __builtin_popcount(i);

			for (int j = 0; j <= 7; j++) {
				if (i & (1 << j)) {
					denom = denom * primes[j];
				}
			}

			if (setBits & 1) {
				ans += n / denom; //if number of set bits are odd add
			}
			else ans -= n / denom; //if number of set bits are even subtract
		}

		cout << ans << '\n';

	}
	return 0;
}