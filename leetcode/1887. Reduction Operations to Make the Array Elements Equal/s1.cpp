// OJ: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pre = nums[0], ans = 0, cnt = 0;
        for (int i = 1; i < n; i++){
            if (nums[i] == pre)
                ans += cnt;
            else{
                cnt++;
                ans += cnt; 
                pre = nums[i];
            }
        }
        return ans;
    }
};
