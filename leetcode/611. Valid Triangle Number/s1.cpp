// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/punkfulw
// Time: O(N^2logN)
// Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; i++){
            int cur = nums[i];
            for (int j = i+1; j < n-1; j++){
                int next = nums[j];
                int lower = cur + next;
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), lower);
                ans +=  it - (nums.begin() + j + 1);
            }
        }
        return ans;
    }
};
