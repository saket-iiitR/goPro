// Generate all the subsets using bitmasking

// Concept : Total number of subsets of an array of n elements = 2^n
// --------  So what we can do is, is for a number in range 0 to 2^n if a particular
// 		  bit is set, we add this element to our set.
// 		  example: for array of 8 elements total number of possible subsets = 2^8 = 256
// 		  for i=0 to i<256:
// 		  	for j=0 to j<8:
// 		  		if(jth bit is set)
// 		  			print the ith element of array

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char arr[] = {'A', 'B', 'C', 'D'};
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;

		int total = 1 << n;

		for (int mask = 0; mask < total; mask++) {
			for (int i = 0; i < n; i++) {
				int f = 1 << i;
				if ((mask & f) != 0)
					cout << arr[i] << ' ';
			}

			cout << endl;
		}
	}

	return 0;
}
