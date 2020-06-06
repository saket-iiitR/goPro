// Big Integer Factorial

#include <bits/stdc++.h>
using namespace std;
int arr[1000];

void multiply(int &size, int n) {
    int carry = 0;
    int product = 1;
    for (int i = 0; i < size; i++) {
        product = arr[i] * n + carry;
        arr[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        arr[size] = carry % 10;
        carry = carry / 10;
        size++;
    }

}

// n! = 1*2*3*4*......* n-1 *n
// we are multiplying every value in array with i

void solve(int n) {
    int size = 1;
    for (int i = 2; i <= n; i++) {
        multiply(size, i);
    }
    for (int i = size - 1; i >= 0; i--)
        cout << arr[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, 0, sizeof(arr));
    arr[0] = 1;

    int n;
    cin >> n;
    solve(n);

    return 0;
}