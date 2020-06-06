#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];

int minCost(int n, int k) {
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i <= min(k, n); i++)
        dp[i] = abs(arr[i] - arr[0]);

    if (k < n) {
        for (int i = k + 1; i < n; i++) {
            int ans = INT_MAX;
            for (int j = i - 1; j >= i - k; j--) {
                ans = min(ans, dp[j] + abs(arr[i] - arr[j]));
            }
            dp[i] = ans;
        }
    }

    return dp[n - 1];
}

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minCost(n, k);
    return 0;
}
