// OJ: https://leetcode.com/problems/jump-game-vi/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/jump-game-vi/discuss/978544/C%2B%2B-DP-%2B-Pruning-vs.-Monodeq
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq{0};
        for (int i = 1; i < nums.size(); i++){
            if (dq.front() + k < i)
                dq.pop_front();
            nums[i] += nums[dq.front()];
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return nums.back();
    }
};
