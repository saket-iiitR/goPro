#include <bits/stdc++.h>
using namespace std;
#define int long long

//dp ke states-> [digit][strict condition][pehle 3 aaya hai]
// maximum digit = 9
// tight condition = 2
// tight condition kya hai - > ?
// let n = 3 4 5 6
// to 1st index pr agar 3 hai to 2nd index me number must be less than equal to 4
// 3rd index pr number must be less than equal to 5

int dp[10][2][2];

int notThree(string str, int pos = 0, bool tight = 1, bool three = 0) {
	if (pos == str.size())
		if (three)
			return 1;
		else return 0;

	else if (dp[pos][tight][three] != -1)
		return dp[pos][tight][three];

	else if (tight) {
		int res = 0;
		for (int i = 0; i <= str[pos] - '0'; i++) {
			int flag = three;
			if (i == 3)
				flag = true;
			if (i == str[pos] - '0')
				res += notThree(str, pos + 1, 1, flag);
			else
				res += notThree(str, pos + 1, 0, flag);
		}
		return dp[pos][tight][three] = res;
	}
	else {
		int res = 0;
		for (int i = 0; i <= 9; i++) {
			int flag = three;
			if (i == 3)
				flag = true;
			res += notThree(str, pos + 1, 0, flag);
		}
		return dp[pos][tight][three] = res;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string a = to_string(n);
		memset(dp, -1, sizeof dp);
		int ans = notThree(a);
		cout << n - ans << endl;
	}
	return 0;
}