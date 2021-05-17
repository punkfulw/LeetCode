// OJ: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        return unordered_multiset<int>(arr.begin(), arr.end()) == unordered_multiset<int>(target.begin(),target.end());
    }
};
