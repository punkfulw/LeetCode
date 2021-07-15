// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/remove-duplicates-from-sorted-array/discuss/11782/Share-my-clean-C%2B%2B-code
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1])
                index++;
            else
                nums[i - index] = nums[i];                
        }
        return nums.size() - index;
    }
};
