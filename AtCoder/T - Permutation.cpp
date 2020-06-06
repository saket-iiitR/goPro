#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int n;
const int mod = 1e9 + 7;
int dp[3001][3001];

void solve() {
	dp[n][0] = (s[n - 2] == '>') ? 1 : 0;
	dp[n][1] = (s[n - 2] == '<') ? 1 : 0;

	for (int i = n - 1; i >= 2; i--) {
		int total = n - i + 1;
		for (int g = 0; g <= total; g++) {
			if (g == 0) {
				if (i == n) continue;
				dp[i][g] = 0;
				if (s[i - 2] == '<') continue;
				for (int j = 1; j <= total; j++)
					dp[i][g] = (dp[i][g] + dp[i + 1][total - j]) % mod;
			}
			else {
				if (s[i - 2] == '>')
					dp[i][g] = (mod + dp[i][g - 1] - dp[i + 1][g - 1]) % mod;
				else
					dp[i][g] = (dp[i][g - 1] + dp[i + 1][g - 1]) % mod;
			}
		}
	}
}

int32_t main()
{
	cin >> n >> s;
	solve();
	int ans = 0;
	for (int greater = n - 1; greater >= 0; greater--)
		ans = (ans + dp[2][greater]) % mod;
	cout << ans;
	return 0;
}
