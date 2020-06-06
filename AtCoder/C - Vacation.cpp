#include <bits/stdc++.h>
using namespace std;

int maxHappy() {

    int n; cin >> n;
    int happy[n][3];
    for (int i = 0; i < n; i++)
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];

    if (n > 1) {
        for (int i = 1; i < n; i++) {
            happy[i][0] = happy[i][0] + max(happy[i - 1][1] , happy[i - 1][2]);
            happy[i][1] = happy[i][1] + max(happy[i - 1][0] , happy[i - 1][2]);
            happy[i][2] = happy[i][2] + max(happy[i - 1][0] , happy[i - 1][1]);
        }
    }

    int ans = happy[n - 1][0];
    ans = max(ans, (max(happy[n - 1][1], happy[n - 1][2])));
    return ans;
}

int main()
{
    cout << maxHappy();
    return 0;
}
