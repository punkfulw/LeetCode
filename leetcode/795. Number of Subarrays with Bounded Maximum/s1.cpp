// OJ: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/discuss/117616/C%2B%2B-O(n)-less10-lines
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l = -1, r = -1;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] >= left)
                r = i;
            if (nums[i] > right)
                l = i;
            ans += r - l;
        } 
        return ans;
    }
};
