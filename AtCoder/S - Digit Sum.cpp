#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
string str;
int D;
int dp[10010][101][2];
// pos can vary upto 10,000
// d can vary from 0 to 100 as d = (D+d - x%D)%D
// tight varies 0 or 1

int digitdp(int pos = 0, int d = 0, bool tight = true) {

	if (dp[pos][d][tight] != -1)
		return dp[pos][d][tight];

	int limit = (tight) ? (str[pos] - '0') : 9;

	if (pos == str.length() - 1) {
		int ans = 0;
		for (int x = 0; x <= limit; x++)
			if (x % D == d)
				ans++;
		return ans;
	}

	int ans = 0;
	for (int x = 0; x <= limit; x++)
		ans = (ans + digitdp(pos + 1, (D + d - x % D) % D, tight && (x == limit))) % mod;
	return dp[pos][d][tight] = ans;
}
int32_t main()
{
	cin >> str >> D;
	memset(dp, -1, sizeof dp);
	cout << (mod + digitdp() - 1) % mod << endl;
	return 0;
}
