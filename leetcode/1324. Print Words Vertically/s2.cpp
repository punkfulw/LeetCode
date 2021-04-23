// OJ: https://leetcode.com/problems/print-words-vertically/
// Author: github.com/punkfulw
// Time: O(S)
// Space: O(S)
//reference: https://github.com/lzl124631x/LeetCode/tree/master/leetcode/1324.%20Print%20Words%20Vertically
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v, ans;
        stringstream ss(s);
        string word;
        int maxLen = 0;
        while (ss >> word) {
            v.push_back(word);
            maxLen = max(maxLen, (int)word.size());
        }
        for (int i = 0; i < maxLen; ++i) {
            string word;
            for (int j = 0; j < v.size(); ++j)
                word += i < v[j].size() ? v[j][i] : ' ';
            while (word.back() == ' ') word.pop_back();
            ans.push_back(word);
        }
        return ans;
    }
};
