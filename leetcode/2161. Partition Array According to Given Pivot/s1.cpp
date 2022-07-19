// OJ: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int p) {
        int n = nums.size(), small = 0, equal = 0, big = 0;
        
        for (auto &i: nums){
            if (i > p) big++;
            else if (i == p) equal++;
            else small++;
        }
        int pos_s = 0, pos_e = small, pos_b = small + equal;
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            if (nums[i] < p)
                ans[pos_s++] = nums[i];
            else if (nums[i] == p)
                ans[pos_e++] = nums[i];
            else
                ans[pos_b++] = nums[i];  
        }
        
        return ans;
    }
};
