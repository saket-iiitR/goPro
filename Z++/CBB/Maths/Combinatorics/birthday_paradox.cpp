#include <bits/stdc++.h>
using namespace std;

int solve(int percentage) {

	// What we are doing here is:
	// 1. Probability that they will have birthday on same day = p;

	// 2. Therefore Probability that they will not have birthday on same day = 1-p =x;

	// 3. x1 = 365/365 ->100% that no one will have birthday on same day
	// 	x2 = 365/365 * 364/365 -> probability that 2 person will not have birthday on same day
	// 	x3 =  365/365 * 364/365 * 363/365 -> probability that 2 person will not have birthday on same day

	// 4. Therefore ,
	// 	probability that 2 person will have birthday on same day = 1 - 365/365 * 364/365 = 1-x2
	// 	probability that 3 person will have birthday on same day = 1 - 365/365 * 364/365 * 363/365 = 1-x3


	if (percentage == 100)
		return 1;

	int n = 1;
	double prev_ans = 1;
	double numerator = 365;
	double denominator = 365;
	double curr_ans = 1;
	int i;
	for (i = 2; i < 366; i++) {
		curr_ans = prev_ans * ((numerator - i + 1) / denominator);
		if (curr_ans * 100 <= percentage)
			break;
		prev_ans = curr_ans;
	}
	return i;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int percentage;
		cin >> percentage;

		cout << solve(percentage) << endl;
	}
	return 0;
}
