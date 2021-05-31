// OJ: https://leetcode.com/problems/keyboard-row/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/keyboard-row/discuss/97872/C%2B%2B-solution-with-3-hash-tables
// Time: O(NM)
// Space: O(1)
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<unordered_set<char>> dict = {
            {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'},
            {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'},
            {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'}};

        vector<string> res;

        for (auto &word : words) {
            vector<bool> d(3, true);

            for (auto &ch : word)
                for (int i = 0; i < 3; ++i)
                    if (d[i] && dict[i].find(ch) == dict[i].end())
                        d[i] = false;

            if (d[0] || d[1] || d[2])
                res.push_back(word);
        }
        return res;
    }
};
