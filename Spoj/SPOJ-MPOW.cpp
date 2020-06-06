#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const long long size  = 101;


struct matrix
{
    long long mat[size][size];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }

    void fill_v(long long dim) {
        for (long long i = 0; i < dim; i++)
            for (long long j = 0; j < dim; j++)
                cin >> mat[i][j];
    }

    void print_v(long long dim) {
        for (long long i = 0; i < dim; i++) {
            for (long long j = 0; j < dim; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    void identity() {
        for (long long i = 0; i < size; i++)
            mat[i][i] = 1;
    }

    matrix operator* (const matrix &a ) const {
        matrix r;
        for (long long i = 0; i < size; i++)
            for (long long j = 0; j < size; j++)
                for (long long k = 0; k < size; k++)
                    r.mat[i][j] = (r.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
        return r;
    }
};

void solve(long long dim, long long n) {
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t, dim, pow;
    cin >> t;
    while (t--) {
        cin >> dim >> pow;
        solve(dim, pow);
    }

    return 0;
}