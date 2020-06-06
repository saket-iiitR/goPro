#include <bits/stdc++.h>
using namespace std;
int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        if (n == 0 or n == 1) cout << 1 << endl;
        else {
            memset(arr, 0, sizeof arr);
            arr[0] = 2;

            for (int no = 3; no <= n; no++) {
                int carry = 0;
                for (int j = 0; j < 100000; j++) {

                    arr[j] = arr[j] * no + carry;
                    carry = arr[j] / 10;
                    arr[j] = arr[j] % 10;
                }
            }

            //Print no
            bool flag = false;
            for (int i = 100000; i >= 0; i--) {
                if (arr[i] == 0 and flag == false)
                    continue;
                else {
                    flag = true;
                    cout << arr[i];
                }
            }
            cout << endl;
        }
    }
    return 0;
}