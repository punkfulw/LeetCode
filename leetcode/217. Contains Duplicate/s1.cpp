// OJ: https://leetcode.com/problems/contains-duplicate/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num: nums){
            if (set.count(num))
                return true;
            else
                set.insert(num);
        }
        return false;
    }
};
