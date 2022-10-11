// OJ: https://leetcode.com/problems/sum-of-beauty-in-the-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(), ans = 0, l[100001] = {}, r[100001] = {};
        int mn = nums.back(), mx = nums[0];
        
        for (int i = 1; i < n - 1; i++){
            if (nums[i] > mx)
                l[i] = 1;
            mx = max(mx, nums[i]);
            if (nums[n - i - 1] < mn)
                r[n - i - 1] = 1;
            mn = min(mn, nums[n - i - 1]);
        }
   
        for (int i = 1; i < n - 1; i++){
            if (l[i] && r[i])
                ans += 2;
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
                ans++;
        }
        return ans;
    }
};
