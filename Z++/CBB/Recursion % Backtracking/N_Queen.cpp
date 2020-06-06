#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[][10], int start, int pos, int n) {

	// Valid tabhi hoga jab :
	// 1. Us pure column me koi queen na ho
	// 2. Uske left diagonal me koi queen na ho
	// 3. Uske right diagonal me koi queen na ho

	// 1. Column check
	for (int i = 0; i < start; i++)
		if (arr[i][pos])
			return false;

	// 2. Left diagonal
	int i = start - 1;
	int j = pos - 1;
	while (i >= 0 && j >= 0) {
		if (arr[i][j])
			return false;
		i--;
		j--;
	}

	// 3. Right diagonal
	i = start - 1;
	j = pos + 1;
	while (i >= 0 && j < n) {
		if (arr[i][j])
			return false;
		i--;
		j++;
	}

	return true;
}

bool NqueenProb(int arr[][10], int start, int n) {

	//Base Case

	// If all n Queens are successfully placed, print all

	if (start == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j])
					cout << "Q ";
				else cout << "_ ";
			}
			cout << endl;
		}

		cout << endl << endl;
		return false;
	}

	// Recursive Solution
	// Recursive solution me hum check krenge sirf current postion ka
	// baaki hamara recursion solve kr k le aayga

	// Try to place queen at a valid position in every column
	for (int j = 0; j < n; j++) {
		if (isValid(arr, start, j, n)) {
			// Place Queen
			arr[start][j] = 1;

			// We will check ki ye hum aage bhi queen rakh paay
			bool nextQueenRakhPaynge = NqueenProb(arr, start + 1, n);
			if (nextQueenRakhPaynge)
				return true;

		}

		// Yahan pr tab hi aaynge jab queen nahi rakh paay
		// To humein wapas se 0 karna pdega queen
		arr[start][j] = 0;

	}

	// I have tried for all the positions and didnt found a suitable pos

	return false;

}

int main()
{
	int n; cin >> n;
	int arr[10][10] = {0};

	NqueenProb(arr, 0, n);


	return 0;
}
