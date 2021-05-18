// OJ: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans {};
        int sum = accumulate(nums.begin(), nums.end(), 0);
        priority_queue<int> pq {};
        
        for (int i: nums){
            pq.push(i);
        }
        
        while (accumulate(ans.begin(), ans.end(), 0) <= sum){
            sum -= pq.top();
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
