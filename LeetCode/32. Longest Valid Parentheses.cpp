#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {
    // cout << s << endl;
    int n = s.length();
    if (n == 0 or n == 1) return 0;
    int currLen = 0;
    int prevLen = 0;
    stack<int>st;
    bool flag = false;
    int maxi = 0;

    for (int i = 0; i < n; i++) {
        if (!flag and s[i] == ')')
            continue;
        else {
            if (s[i] == '(') {
                flag = true;
                st.push(currLen);
                currLen = 0;
            }
            else if (s[i] == ')' and st.empty())
                currLen = 0;
            else if (s[i] == ')' and !st.empty()) {
                prevLen = st.top();
                currLen = currLen + prevLen + 2;
                maxi = max(maxi, currLen);
                st.pop();
            }
        }
    }
    return maxi;

}

int main()
{
    string s = ")()())()()(";
    cout << longestValidParentheses(s);
    return 0;
}