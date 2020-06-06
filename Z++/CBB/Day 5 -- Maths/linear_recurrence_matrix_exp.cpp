#include <bits/stdc++.h>
using namespace std;
#define int long long int

const int mod = 1e9;
const int size  = 10;


struct matrix
{
    int mat[size][size];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }

    void identity() {
        for (int i = 0; i < size; i++)
            mat[i][i] = 1;
    }

    matrix operator* (const matrix &a ) const {
        matrix r;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                for (int k = 0; k < size; k++)
                    r.mat[i][j] = (r.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
        return r;
    }
};

int solve(int b[], int c[], int k, int n) {

    if (n <= k) {
        return b[n - 1];
    }

    matrix res, a;
    res.identity();

    for (int i = 0; i < k; i++)
        a.mat[0][i] = c[i];

    for (int i = 1; i < k; i++)
        a.mat[i][i - 1] = 1;

    n = n - k;

    while (n) {
        if (n & 1)
            res = res * a;
        n /= 2;
        a = a * a;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += (res.mat[0][i] * b[k - i - 1]);
        ans %= mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;
    cin >> t;
    while (t--) {
        cin >> k;
        int b[k], c[k];
        for (int i = 0; i < k; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];
        int n;
        cin >> n;
        cout << solve(b, c, k, n) << '\n';
    }

    return 0;
}