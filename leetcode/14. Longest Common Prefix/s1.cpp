// OJ: https://leetcode.com/problems/longest-common-prefix/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = *min_element(strs.begin(), strs.end());
        int n = pre.size();
        for (int i = 0; i < strs.size(); i++){
            for (int j = 0; j < n; j++){
                if (pre[j] != strs[i][j] && j == 0)
                    return "";
                if (pre[j] != strs[i][j])
                        pre = pre.substr(0, j);
            }
        }
        return pre;
    }
};
