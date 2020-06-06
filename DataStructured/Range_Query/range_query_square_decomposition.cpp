#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000000];
int sdec[1000];
int block;

int get_min(int l, int r)
{
    int left_block = l / block;
    int right_block = r / block;
    int mini = INT_MAX;

    if (left_block == right_block)
        for (int i = l; i <= r; i++)
            mini = min(arr[i], mini);

    else
    {
        for (int i = l; i < block * (left_block + 1); i++)
            mini = min(mini, arr[i]);

        for (int i = left_block + 1; i < right_block; i++)
            mini = min(mini, sdec[i]);

        for (int i = block * right_block; i <= r; i++)
            mini = min(mini, arr[i]);
    }
    return mini;
}


void sqrtDecomp()
{
    block = floor(sqrt(n));

    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (i % block == 0)
        {
            sdec[(i / block) - 1] = mini;
            mini = arr[i];
        }
        if (mini > arr[i])
            mini = arr[i];
    }
    sdec[block - 1] = mini;

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(sdec, 0, sizeof(sdec));

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sqrtDecomp();

    int q;
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        cout << get_min(l, r) << "\n";
    }

    return 0;
}

