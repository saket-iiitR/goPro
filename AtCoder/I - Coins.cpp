#include <bits/stdc++.h>
using namespace std;

void coin() {
	int n; cin >> n;
	vector<double>prob(n);
	for (int i = 0; i < n; i++)
		cin >> prob[i];

	double dp[n + 1][n + 1];
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = (1 - prob[i - 1]) * dp[i - 1][0];
	for (int i = 1; i <= n; i++)
		dp[0][i] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = prob[i - 1] * dp[i - 1][j - 1] + (1 - prob[i - 1]) * dp[i - 1][j];

	int min = (n + 1) / 2;
	double ans = 0;
	for (int i = min; i <= n; i++)
		ans += dp[n][i];
	cout << setprecision(10) << ans << endl;
	return ;
}

int main()
{
	coin();
	return 0;
}

// for (int i = 0; i <= n; i++) {
// 		for (int j = 0; j <= n; j++)
// 			cout << dp[i][j] << " ";
// 		cout << endl;
// 	}
