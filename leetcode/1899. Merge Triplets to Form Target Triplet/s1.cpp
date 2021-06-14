// OJ: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/discuss/1268473/Greedy
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& target) {
        vector<int> ans(3);
        for (auto s: tri){
            if (s[0] <= target[0] && s[1] <= target[1] && s[2] <= target[2])
                ans = {max(s[0], ans[0]), max(s[1], ans[1]), max(s[2], ans[2])};
        }
        return ans == target;
    }
};
