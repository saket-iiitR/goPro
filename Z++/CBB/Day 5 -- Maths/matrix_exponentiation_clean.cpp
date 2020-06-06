#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;
int k;
vector<int> b, c;
// vector a will store values of coeficient of recurrence relation
// Ex: f(n) = f(n-1) + f(n-2) :: a= {1,1};
// vector b will store values of constatnts in recurrence relation
// Ex: f(n) = f(n-1) + f(n-2) + d + e + f :: b= {d,e,f};

vector < vector<int>> multiply(vector < vector<int>> A, vector < vector<int>> B) {

    // For storing ans
    vector < vector<int>> C(k + 1, vector<int> (k + 1));

    // Multiplication logic:
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 1; x <= k; x++) {
                C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % mod ) % mod;
            }
        }
    }

    return C;
}

vector < vector<int>> pow(vector < vector<int>> A, int p) {
    // Multiplicative Exponentiation
    //base case:
    if (p == 1)
        return A;

    // if p is odd
    if (p & 1)
        return multiply(A, pow(A, p - 1));

    vector < vector<int>> X = pow(A, p / 2);

    return multiply(X, X);
}

int compute(int n) {
    // This is the main function for the logic ton run
    // Base Case:
    if (n == 0)
        return 0;
    if (n <= k)
        return b[n - 1];

    // Otherwise use matrix exponentiation

    // Step 1: Making F1 matrix {f(0),f(1)} for fibonacci number
    vector<int> F1(k + 1);
    for (int i = 1; i <= k; i++)
        F1[i] = b[i - 1];

    // Step 2: Making Transformation Matrix :
    // 1: Shifted Identity Matrix for all the columns except last
    // 2: For last column reversed 'a' vector i.e coefficient vector
    // Check notes in case of confusion
    vector < vector<int>> T(k + 1, vector<int>(k + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i < k) {
                //fill 0's and 1's
                if (j == i + 1)
                    T[i][j] = 1;
                else
                    T[i][j] = 0;
            }
            else
                T[i][j] = c[k - j];

        }
    }


    // Step 3: F(n) = T^(n-1) * F(n-1);
    T = pow(T, n - 1);

    // Step 4: Multiplication with F1 and 1st column of Transformation Matrix
    int result = 0;
    for (int i = 1; i <= k; i++)
        result = (result + (T[1][i] * F1[i]) % mod) % mod;

    return result;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    k = 2;
    b.push_back(1);
    b.push_back(2);
    c.push_back(1);
    c.push_back(1);

    int t; cin >> t;
    int n, num;
    while (t--)
    {
        cin >> n;
        cout << compute(n) << endl;
    }
    return 0;
}