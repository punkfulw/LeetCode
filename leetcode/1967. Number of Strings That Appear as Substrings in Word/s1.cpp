// OJ: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto pat: patterns)
            if (word.find(pat) != std::string::npos)
                ans++;
        return ans;
    }
};
