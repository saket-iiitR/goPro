#include <bits/stdc++.h>
using namespace std;
#define int long long
int arr[10000];
int dp[10000];
int n, k;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int recursion() {

    for (int i = 0; i < n; i++) {
        if (i - k - 1 >= 0)
            dp[i] = max(dp[i - k - 1] + arr[i], dp[i - 1]);
        else {
            if (i != 0)
                dp[i] = max(arr[i], dp[i - 1]);
            else
                dp[i] = max(arr[i], 0);
        }
    }
    return *max_element(dp, dp + n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        memset(arr, 0, sizeof arr);
        memset(dp, 0, sizeof dp);
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << recursion() << endl;
    }
    return 0;
}


