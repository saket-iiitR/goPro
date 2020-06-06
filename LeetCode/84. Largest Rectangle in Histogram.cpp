#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    if (n == 1) return heights[0];

    int left[n], right[n];
    for (int i = 0; i < n; i++) {
        left[i] = -1;
        right[i] = n;
    }

    stack<int> lft, rgt;
    rgt.push(0);
    for (int i = 1; i < n; i++) {
        if (heights[rgt.top()] > heights[i]) {
            while (!rgt.empty() and heights[rgt.top()] > heights[i]) {
                right[rgt.top()] = i;
                rgt.pop();
            }
            rgt.push(i);
        }
        else rgt.push(i);
    }

    lft.push(n - 1);
    for (int i = n - 2; i >= 0; i--) {
        if (heights[lft.top()] > heights[i]) {
            while (!lft.empty() and heights[lft.top()] > heights[i]) {
                left[lft.top()] = i;
                lft.pop();
            }
            lft.push(i);
        }
        else lft.push(i);
    }

    for (int i = 0; i < n; i++) {
        right[i] = (right[i] - left[i] - 1) * heights[i];
    }

    return *max_element(right, right + n);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> heights = {1, 1};
    cout << largestRectangleArea(heights);
    return 0;
}