// OJ: https://leetcode.com/problems/valid-triangle-number
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/valid-triangle-number/discuss/104177/O(N2)-solution-for-C%2B%2B-and-Python
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int k = n - 1; k > 1; k--){
            int i = 0, j = k - 1;
            while (i < j){
                if (nums[i] + nums[j] > nums[k])
                    ans += --j - i + 1;
                else
                    i++;
            }
        }
        return ans;
    }
};
