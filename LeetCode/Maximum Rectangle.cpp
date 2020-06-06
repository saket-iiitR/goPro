#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& temp) {
    int n = temp.size();
    if (n == 0) return 0;

    int ans = INT_MIN;
    stack<int>lft, rgt;
    int left[n], right[n];
    for (int i = 0; i < n; i++) {
        left[i] = -1;
        right[i] = n;
    }
    rgt.push(0);
    for (int i = 1; i < n; i++) {
        if (temp[rgt.top()] > temp[i]) {
            while (!rgt.empty() and temp[rgt.top()] > temp[i]) {
                right[rgt.top()] = i;
                rgt.pop();
            }
            rgt.push(i);
        }
        else rgt.push(i);
    }

    lft.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (temp[lft.top()] > temp[i]) {
            while (!lft.empty() and temp[lft.top()] > temp[i]) {
                left[lft.top()] = i;
                lft.pop();
            }
            lft.push(i);
        }
        else lft.push(i);
    }

    for (int i = 0; i < n; i++)
        right[i] = (right[i] - left[i] - 1) * temp[i];

    return *max_element(right, right + n);
}

int maximalRectangle(vector<vector<char>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    if (n == 0 and m == 0) return 0;

    vector<vector<int>> heights (n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == '1')
                heights[i][j] = 1;
            else if (matrix[i][j] == '0')
                heights[i][j] = 0;

    for (int j = 0; j < m; j++)
        for (int i = 1; i < n; i++)
            if (heights[i][j] != 0)
                heights[i][j] += heights[i - 1][j];

    vector<int>temp;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {

        temp.clear();
        for (int j = 0; j < m; j++)
            temp.push_back(heights[i][j]);

        for (int j = 0; j < m; j++)
            cout << temp[j] << " ";
        cout << endl;

        ans = max(ans, largestRectangleArea(temp));
    }

    return ans;

}

int main()
{
    vector<vector<char>> matrix = { {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}