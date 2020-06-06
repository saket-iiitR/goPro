class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int>circular;

        if (nums.size() == 0)
            return circular;

        int n = nums.size();

        // Jab bhi hmein circular array aayga, hm 2*array store krenge
        for (int i = 0; i < n; i++)
            circular.push_back(nums[i]);
        for (int i = 0; i < n; i++)
            circular.push_back(nums[i]);

        vector<int>ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = -1;

        stack<int> st;
        st.push(0);
        for (int i = 1; i < circular.size(); i++) {
            if (circular[st.top()] < circular[i] and st.top() < n) {
                while (st.empty() == false and circular[st.top()] < circular[i]) {
                    ans[st.top()] = circular[i];
                    st.pop();
                }
                if (i < n) st.push(i);
            }
            else if (i < n) st.push(i);
        }

        return ans;


    }
};