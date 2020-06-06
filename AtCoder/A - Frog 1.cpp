#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];

int minCost(int n) {
    int dp[n];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);

    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]), dp[i - 2] + abs(arr[i] - arr[i - 2]));
    }

    return dp[n - 1];
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minCost(n);
    return 0;
}
