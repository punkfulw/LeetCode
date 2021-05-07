// OJ: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL)
            return 0;
        int h = 0;
        for (auto x: root->children){
            h = max(maxDepth(x), h);
        }
        return h + 1;
    }
};
