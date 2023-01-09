// OJ: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stk;
        heights.push_back(INT_MAX);
        stk.push(n);
        
        for (int i = n - 1; i >= 0; i--){
            int cnt = 0;
            while (!stk.empty() && heights[i] >= heights[stk.top()]){
                cnt++;
                stk.pop();
            }
            cnt += stk.top() == n ? 0 : 1;
            ans[i] = cnt;
            stk.push(i);
        }
        return ans;
    }
};
