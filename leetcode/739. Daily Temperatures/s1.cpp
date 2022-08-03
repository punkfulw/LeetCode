// OJ: https://leetcode.com/problems/daily-temperatures/
// Author: github.com/punkfulw
// Time: O(S)
// Space: O(S)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<pair<int, int>> stk;
        for (int i = nums.size() - 1; i >= 0; i--){
            int cur = nums[i];
            if (stk.empty())
                nums[i] = 0;
            else{
                while (!stk.empty() && cur >= stk.top().second)
                    stk.pop();
                if (stk.empty())
                    nums[i] = 0;
                else
                    nums[i] = stk.top().first - i;
            }
            stk.push({i, cur});
        }
        return nums;
    }
};
