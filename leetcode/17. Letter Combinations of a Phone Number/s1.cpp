// OJ: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/17.%20Letter%20Combinations%20of%20a%20Phone%20Number/README.md
// Time: O(4^N)
// Space: O(N)
class Solution {
    vector<string> m{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(string &digits, int start, string &str) {
        if (start == digits.size()) {
            ans.push_back(str);
            return;
        }
        for (char c : m[digits[start] - '2']) {
            str.push_back(c);
            dfs(digits, start + 1, str);
            str.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string str;
        dfs(digits, 0, str);
        return ans;
    }
};
