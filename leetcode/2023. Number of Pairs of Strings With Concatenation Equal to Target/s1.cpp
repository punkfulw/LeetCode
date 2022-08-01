// OJ: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
// Author: github.com/punkfulw
// Time: O(N^2) 
// Space: O(1) 
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] != target.substr(0, nums[i].size()))
                continue;
            for (int j = 0; j < n; j++)
                if (nums[i] + nums[j] == target && i != j)
                    ans++;
        }
        return ans;
    }
};
