// Codeforces : 101343H - H. Give Me This Pizza

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans[n];
    for (int i = 0; i < n; i++)
        ans[i] = -1;

    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++) {
        if (arr[st.top()] < arr[i]) {
            while (st.empty() == false and arr[st.top()] < arr[i] ) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        else st.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";


    return 0;
}