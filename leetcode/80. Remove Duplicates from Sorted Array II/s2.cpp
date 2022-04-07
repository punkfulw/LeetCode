// OJ: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/27976/3-6-easy-lines-C%2B%2B-Java-Python-Ruby
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        for (int num: nums)
            if (pos < 2 || num > nums[pos-2])
                nums[pos++] = num;
        return pos;
    }
};
