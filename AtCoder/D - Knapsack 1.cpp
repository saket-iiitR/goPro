#include <bits/stdc++.h>
using namespace std;
#define int long long

int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

int knapSack() {

    int n, capacity; cin >> n >> capacity;
    int weight[n];
    int value[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (weight[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][capacity];
}

int32_t main()
{
    cout << knapSack();
    return 0;
}