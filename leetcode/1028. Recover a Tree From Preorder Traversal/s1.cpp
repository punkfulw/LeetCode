// OJ: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/discuss/274621/JavaC%2B%2BPython-Iterative-Stack-Solution
// Time: O(S)
// Space: O(H) where H is depth of tree
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*> stack;
        for (int i = 0, level, val; i < s.size();)
        {
            level = val = 0;
            while (s[i] == '-')
            {
                i++;
                level++;
            }
            while (level < stack.size())
                stack.pop_back();
            
            while (i < s.size() && s[i] != '-')
                val = val * 10 + (s[i++] - '0');
            TreeNode* newN = new TreeNode(val);
            if (!stack.empty())
            {
                if (stack.back()->left)
                    stack.back()->right = newN;
                else
                    stack.back()->left = newN;
            }
            stack.push_back(newN);
        }
        return stack[0];
    }
};
