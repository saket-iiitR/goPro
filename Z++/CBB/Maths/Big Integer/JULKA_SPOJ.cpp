#include <bits/stdc++.h>
using namespace std;
int arr[110];
int val[110];
int maxi[110];

void subtract() {

    for (int i = 0; i < 110; i++) {
        if (arr[i] < maxi[i]) {
            arr[i] = 10 + arr[i];
            arr[i + 1]--;
        }
        arr[i] = arr[i] - maxi[i];
    }

}

void divide() {

    for (int i = 109; i >= 0; i--) {
        if (arr[i] == 1 && i >= 1) {
            arr[i - 1] = 10 + arr[i - 1];
            arr[i] = 0;
        }
        else if (arr[i] % 2 == 0)
            arr[i] = arr[i] / 2;
        else if (arr[i] % 2 != 0) {
            if (i >= 1) {
                arr[i - 1] = 10 + arr[i - 1];
                arr[i] = arr[i] / 2;
            }
            else arr[i] /= 2;
        }
    }

}

void add() {
    int carry = 0;
    int sum = 0;
    for (int i = 0; i < 110; i++) {
        sum = (arr[i] + maxi[i] + carry );
        arr[i] = sum % 10;
        carry = sum / 10;
    }
}

void solve(string total, string greater) {

    reverse(total.begin(), total.end());
    reverse(greater.begin(), greater.end());

    int total_sz = total.size();
    for (int i = 0; i < total_sz; i++) {
        arr[i] = total[i] - '0';
    }

    int greater_sz = greater.size();
    for (int i = 0; i < greater_sz; i++)
        maxi[i] = greater[i] - '0';

    subtract(); // total - greater
    divide(); // (total - greater)/2 == x ;

    for (int i = 0; i < 110; i++)
        val[i] = arr[i]; //Natalia

    add();
    //Klaudia
    int i;
    for (i = 109; i > 0; i--)
        if (arr[i] != 0)
            break;
    for ( ; i >= 0; i--)
        cout << arr[i];
    cout << endl;


    for (i = 109; i > 0; i--)
        if (val[i] != 0)
            break;
    for ( ; i >= 0; i--)
        cout << val[i];
    cout << endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 10;
    while (t--)
    {
        memset(val, 0, sizeof(val));
        memset(arr, 0, sizeof(arr));
        memset(maxi, 0, sizeof(maxi));

        string total, greater ;
        cin >> total >> greater ;

        solve(total, greater);
    }
    return 0;
}