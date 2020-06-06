#include < bits / stdc++.h >
using namespace std;
#define int long long
#define inf 1e18

int max(int a, int b) {
    if (a >= b) return a;
    return b;
}

int min(int a, int b) {
    if (a >= b) return b;
    return a;
}


int knapSack() {
    int n, capacity;
    cin >> n >> capacity;

    int weight[n], val[n];
    int valSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
        valSum += val[i];
    }

    int ans = 0;

    int dp[n + 1][valSum + 1];
    for (int i = 1; i <= valSum; i++)
        dp[0][i] = inf;
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= valSum; j++) {
            if (val[i] <= j)
                dp[i + 1][j] = min(weight[i] + dp[i][j - val[i]], dp[i][j]);
            else
                dp[i + 1][j] = dp[i][j];
            if (dp[i + 1][j] <= capacity)
                ans = max(ans, j);
        }
    }

    return ans;

}
int32_t main()
{
    cout << knapSack();
    return 0;
}