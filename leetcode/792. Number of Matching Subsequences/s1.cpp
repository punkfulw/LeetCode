// OJ: https://leetcode.com/problems/number-of-matching-subsequences/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/number-of-matching-subsequences/discuss/117575/C%2B%2B-12-Line-Solution-with-Explanation
// Time: O(S + NWlogS)
// Space: O(S)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& A) {
        vector<int> index[26];
        for (int i = 0; i < s.size(); ++i) index[s[i] - 'a'].push_back(i);
        int ans = 0;
        for (auto &w : A) {
            int i = 0, j = 0;
            for (; i < w.size(); ++i) {
                auto &v = index[w[i] - 'a'];
                auto it = lower_bound(begin(v), end(v), j);
                if (it == end(v)) break;
                j = *it + 1;
            }
            ans += i == w.size();
        }
        return ans;
    }
};
