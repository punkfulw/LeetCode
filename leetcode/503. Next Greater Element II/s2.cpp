// OJ: https://leetcode.com/problems/next-greater-element-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--){
            if (!st.empty()){
                while (!st.empty() && st.top() <= nums[i % n])
                    st.pop();
                ans[i % n] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
