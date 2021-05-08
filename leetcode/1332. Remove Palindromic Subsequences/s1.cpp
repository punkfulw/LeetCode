// OJ: https://leetcode.com/problems/remove-palindromic-subsequences/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/remove-palindromic-subsequences/discuss/490303/JavaC%2B%2BPython-Maximum-2-Operations
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - equal(s.begin(), s.end(), s.rbegin()) - s.empty();
    }
};
