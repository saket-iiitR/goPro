#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
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
        cout << endl;
    }


    return 0;
}