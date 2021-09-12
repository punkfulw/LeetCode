// OJ: https://leetcode.com/problems/reverse-prefix-of-word/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto it = word.find(ch);
        if (it != string::npos)
            reverse(word.begin(), word.begin() + it + 1);
        return word;
    }
};
