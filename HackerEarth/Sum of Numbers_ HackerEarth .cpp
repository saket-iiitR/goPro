#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[15];

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof(arr));
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int k; cin >> k;
		int subsets = (1 << n) ; // total susets 2^n - 1
		bool flag = false;
		for (int mask = 1; mask < subsets; mask++) {
			int sum = 0;
			for (int i = 0; i < n; i++) {
				int f = 1 << i;
				if ((mask & f) != 0)
					sum += arr[i];
			}
			if (sum == k) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES" << '\n';
		else cout << "NO" << '\n';

	}
	return 0;
}