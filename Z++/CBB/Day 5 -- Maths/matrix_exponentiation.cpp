#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int mod = 1e9 + 7;
const int size  = 101;


struct matrix
{
    int mat[size][size];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }

    void fill_v(int dim) {
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                cin >> mat[i][j];
    }

    void print_v(int dim) {
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
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

void solve(int dim, int n) {
    matrix res, a;

    a.fill_v(dim);

    res.identity();

    while (n) {
        if (n & 1)
            res = res * a;
        n /= 2;
        a = a * a;
    }

    res.print_v(dim);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, dim, pow;
    cin >> t;
    while (t--) {
        cin >> dim >> pow;
        solve(dim, pow);
    }

    return 0;
}