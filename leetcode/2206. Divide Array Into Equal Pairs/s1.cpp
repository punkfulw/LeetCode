// OJ: https://leetcode.com/problems/divide-array-into-equal-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) numbers of different numbers is constant
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int, int> mp;
        
        for (auto i: nums)
            mp[i]++;
        
        for (auto p: mp)
            if (p.second % 2)
                return false;
        return true;
    }
};
