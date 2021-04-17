// OJ: https://leetcode.com/problems/count-the-number-of-consistent-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = words.size();
        bool alpha[26] = {};
        for (char c: allowed) alpha[c - 'a'] = true;
        for (string word: words) {
            for (char c: word) if (!alpha[c - 'a']) {
                ans--;
                break;
            }
        }
        return ans;
    }
};
