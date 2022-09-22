# [513. Find Bottom Left Tree Value (Medium)](https://leetcode.com/problems/find-bottom-left-tree-value/)

<p>
Given a binary tree, find the leftmost value in the last row of the tree. 
</p>

<p><b>Example 1:</b><br>
</p><pre>Input:

    2
   / \
  1   3

Output:
1
</pre>
<p></p>

<p> <b> Example 2: </b><br>
</p><pre>Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
</pre>
<p></p>

<p><b>Note:</b>
You may assume the tree (i.e., the given root node) is not <b>NULL</b>.
</p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/find-bottom-left-tree-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(H)
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while (!q.empty()){
            int sz = q.size(), set = 0;
            while (sz--){
                auto node = q.front();
                q.pop();
                if (!set){
                    ans = node->val;
                    set = 1;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
```
