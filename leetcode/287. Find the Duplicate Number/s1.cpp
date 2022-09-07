// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        
        for (auto i: nums){
            if (set.find(i) != set.end())
                return i;
            set.insert(i);
        }
        return 0;
    }
};
