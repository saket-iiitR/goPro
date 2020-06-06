#include <bits/stdc++.h>
using namespace std;
#define int long long

// number of digits = 8
// maximum sum = 72
// dp[digits][sum][restriction]
int dp[10][80][2];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83};

bool isPrime(int sum) {
	for (int i = 0; i < 23; i++)
		if (sum == prime[i])
			return true;
	return false;
}

int digiSum(string str, int pos = 0, int sum = 0, bool tight = true ) {

	// Base Case: If(pos==length of number return sum)
	if (pos == str.length()) {
		if (isPrime(sum))
			return 1;
		else return 0;
	}

	else if (dp[pos][sum][tight] != -1)
		return dp[pos][sum][tight];

	else if (tight) {
		int res = 0;
		for (int i = 0; i <= str[pos] - '0'; i++) {
			if (i == str[pos] - '0')
				res += digiSum(str, pos + 1, sum + i, 1);
			else {
				//Agar is position se pehle wala number less than max digit hai
				//jaise n= 3 1 2 4 me 1st index pr 3 hai
				// to agar 3 se less koi bhi number ho 0 ya 1 ya 2, to uske liye
				// saare possible combinations valid hai {0-9} tak for nex position
				res += digiSum(str, pos + 1, sum + i, 0);
			}
		}
		return dp[pos][sum][tight] = res;
	}

	else {
		int res = 0;
		for (int i = 0; i <= 9; i++)
			res += digiSum(str, pos + 1, sum + i, 0);
		return dp[pos][sum][tight] = res;
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
		int l, r; cin >> l >> r;
		l = l - 1;
		string a = to_string(l);
		string b = to_string(r);
		memset(dp, -1, sizeof dp);
		int ans1 = digiSum(a);
		memset(dp, -1, sizeof dp);
		int ans2 = digiSum(b);

		cout << ans2 - ans1 << endl;
	}
	return 0;
}