// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
            if (i >= n / 2 && mp[nums[i]] > n/2)
                return nums[i];
        }
        return 0;
    }
};
