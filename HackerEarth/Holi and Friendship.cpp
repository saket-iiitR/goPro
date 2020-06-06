#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int n = 1000;
bool prime[n];

//We are defining 5 states of dp
//  1. pos 2.sum1 3.sum2 4.tight1 5.tight2
int dp[55][500][500][2][2];
string str;

void primeSieve() {
	for (int i = 2; i < n; i++)
		if (i % 2 == 0)
			prime[i] = false;
		else prime[i] = true;

	prime[0] = prime[1] = false;
	prime[2] = true;

	for (int p = 3; p < sqrt(n); p += 2)
		for ( int i = p * p; i < n; i += 2 * p)
			if (prime[i])
				prime[i] = false;

	return;
}

int digitDp(int pos = 0, int sum1 = 0, int sum2 = 0, bool tight1 = 1, bool tight2 = 1) {

	if (pos == str.size()) {
		if (prime[sum1 + sum2] and sum2 < sum1)
			return 1;
		return 0;
	}

	if (dp[pos][sum1][sum2][tight1][tight2] != -1)
		return dp[pos][sum1][sum2][tight1][tight2];

	int limit = (tight1 == true) ? str[pos] - '0' : 9;

	int ans = 0;

	for (int i = 0; i <= limit; i++) {
		int limit2 = (tight2 == true) ? i : 9;
		bool newTight = false;

		if (tight1 and str[pos] - '0' == i)
			newTight = true;

		for (int j = 0; j <= limit2; j++) {
			bool newTight2 = false;

			if (tight2 and i == j)
				newTight2 = true;

			ans = (ans + digitDp(pos + 1, sum1 + i, sum2 + j, newTight, newTight2)) % mod;
		}
	}
	return dp[pos][sum1][sum2][tight1][tight2] = ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	primeSieve();
	cin >> str;
	memset(dp, -1, sizeof dp);
	cout << digitDp();
	return 0;
}

// humlog kya kar rhe hain ?
// to 2 number ka formation kr rhe hai in parallel...jaise jab N ke liye humlog bnate hain to tight condition daalte hain
// ki hamara number N se bada na ho jaay waise hi jab Number1 bnaynge to Number2 ko bhi tight condition denge ki number2
// number1 se bada na ho jaay
// Hama dp har tarah ke digit sum ke value ko store krega jo generate hoga aur digit sum hmesha 450 se chota hoga (9*50)
