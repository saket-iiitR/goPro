#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;

int grid1() {

    int n, m;
    cin >> n >> m;
    int dp[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = -1;

    string str;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++)
            if (str[j] == '#')
                dp[i][j] = 0;
    }

    if (dp[0][0] == 0) return 0;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (dp[i][0] == 0)
            flag = true;
        if (flag) dp[i][0] = 0;
        else dp[i][0] = 1;
    }
    flag = false;
    for (int i = 1; i < m; i++) {
        if (dp[0][i] == 0)
            flag = true;
        if (flag) dp[0][i] = 0;
        else dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (dp[i][j] != 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    return dp[n - 1][m - 1];

}

int32_t main()
{
    cout << grid1();
    return 0;
}


// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < m; j++)
//         cout << dp[i][j] << " ";
//     cout << endl;
// }