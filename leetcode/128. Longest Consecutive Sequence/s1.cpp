// OJ: https://leetcode.com/problems/longest-consecutive-sequence/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/longest-consecutive-sequence/discuss/41060/A-simple-C%2B%2Bsolution-using-unordered_set.And-simple-consideration-about-this-problem
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        
        int ans = 1;
        for (int i: nums){
            if (s.find(i) == s.end()) continue;
            s.erase(i);
            int pre = i-1, next = i+1;
            while (s.find(pre) != s.end()) s.erase(pre--);
            while (s.find(next) != s.end()) s.erase(next++);
            ans = max(ans, next-pre-1);
        }
        
        return ans;
    }
};
