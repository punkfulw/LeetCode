// OJ: https://leetcode.com/problems/sliding-window-maximum/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/sliding-window-maximum/discuss/65898/Clean-C%2B%2B-O(n)-solution-using-a-deque
// Time: O(N)
// Space: O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++){
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
