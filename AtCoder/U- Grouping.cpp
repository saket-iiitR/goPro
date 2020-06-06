#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = LLONG_MAX;
int dp[(1 << 16)];
int sums[(1 << 16)];

int calculate(vector<vector<int>> &score, int mask) {
	int ans = 0;
	for (int i = 0; i < 17; i++)
		for (int j = i + 1; j < 17; j++)
			if (((mask & (1 << i)) != 0) and ((mask & (1 << j)) != 0))
				ans += score[i][j];

	return ans;
}

void prepareSums(vector<vector<int>> &score, int n) {

	for (int subset = 1; subset < (1 << n); subset++)
		dp[subset] = INF;

	for (int subset = 1; subset < (1 << n); subset++)
		sums[subset] = calculate(score, subset);
}

int solve(vector<vector<int>> &score, int mask) {
	if (mask == 0)
		return 0;

	if (dp[mask] != INF)
		return dp[mask];

	int ans = 0;
	for (int submask = mask; submask != 0; submask = (submask - 1) & mask)
		ans = max(ans, sums[submask] + solve(score, mask ^ submask));

	return dp[mask] = ans;
}

int32_t main()
{
	int n; cin >> n;
	vector<vector<int>> score(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> score[i][j];
	prepareSums(score, n);
	cout << solve(score, (1 << n) - 1);
	return 0;
}
