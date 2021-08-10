// OJ: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        if (label == 1)
            return {1};
        int lvl = log2(label)+1;
        vector<int> ans(lvl);
        int n = ans.size();
        int ls = label / 2;
        int left = pow(2, lvl-2);
        ls = pow(2, lvl-1) - 1 - (ls - left);
        ans[n-1] = label;
        ans[n-2] = ls;
        for (int i = n-3; i >= 0; i -= 2) ans[i] = ans[i+2] / 4;
        for (int i = n-4; i >= 0; i -= 2) ans[i] = ans[i+2] / 4;
        return ans;
    }
};
