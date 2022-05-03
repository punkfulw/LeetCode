// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), r = 0, l = -1, mx = nums[0];
        
        for (int i = 0; i < n - 1; i++)
        {
            if (mx > nums[i + 1])
            {
                if (l == -1)
                    l = i;
                int cur = nums[i+1];
                while (l > 0 && nums[l - 1] > cur)
                    l--;
                r = i + 1;   
            }
            else
                mx = nums[i + 1];
        }
        return r == 0 ? 0 : r - l + 1;
    }
};
