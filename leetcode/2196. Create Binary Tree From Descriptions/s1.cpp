// OJ: https://leetcode.com/problems/create-binary-tree-from-descriptions/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/create-binary-tree-from-descriptions/discuss/1823687/C%2B%2B-Map
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {  
        unordered_map<int, TreeNode*> getNode;
        unordered_map<int, bool> ischild;

        for (auto &node : des)
        {
            int curN = node[0], child = node[1], isleft = node[2];
            
            if (getNode.count(curN) == 0)
            {
                TreeNode* newN = new TreeNode(curN);
                getNode[curN] = newN;
            }
            if (getNode.count(child) == 0)
            {
                TreeNode* newN = new TreeNode(child);
                getNode[child] = newN;
            }
            ischild[child] = true;
            isleft == 1 ? getNode[curN]->left = getNode[child] : getNode[curN]->right = getNode[child];
        }
        
        
        TreeNode* ans;
        for (auto &node: des)
        {
            if (!ischild[node[0]])
            {
                ans = getNode[node[0]];
                break;
            }
        }
        
        return ans;
    }
};
