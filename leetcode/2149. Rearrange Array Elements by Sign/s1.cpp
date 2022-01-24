// OJ: https://leetcode.com/problems/rearrange-array-elements-by-sign/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 0;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                while (nums[pos] < 0)
                    pos++;
                res.push_back(nums[pos]);
                pos++;
            }
            else
            {
                while (nums[neg] > 0)
                    neg++;
                res.push_back(nums[neg]);
                neg++;
            }
        }
        return res;
    }
};
