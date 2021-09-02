// OJ: https://leetcode.com/problems/unique-binary-search-trees-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/703236/C%2B%2B-Simple-and-short
// Time: O(N*C(N))
// Space: O(C(N))
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
    vector<TreeNode*> build(int start, int end){
        vector<TreeNode*> v;
        if (start > end){
            v.push_back(NULL);
            return v;
        }
        for (int i = start; i <= end; i++){
            auto left = build(start, i - 1);
            auto right = build(i + 1, end);
            for (auto l: left)
                for (auto r: right){
                    TreeNode* root = new TreeNode(i, l, r);
                    v.push_back(root);
                }
        }
        return v;
    }
};
