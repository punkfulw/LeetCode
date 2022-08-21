# [655. Print Binary Tree (Medium)](https://leetcode.com/problems/print-binary-tree/)

<p>Print a binary tree in an m*n 2D string array following these rules: </p>

<ol>
<li>The row number <code>m</code> should be equal to the height of the given binary tree.</li>
<li>The column number <code>n</code> should always be an odd number.</li>
<li>The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (<b>left-bottom part and right-bottom part</b>). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them. </li>
<li>Each unused space should contain an empty string <code>""</code>.</li>
<li>Print the subtrees following the same rules.</li>
</ol>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
     1
    /
   2
<b>Output:</b>
[["", "1", ""],
 ["2", "", ""]]
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b>
     1
    / \
   2   3
    \
     4
<b>Output:</b>
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b>
      1
     / \
    2   5
   / 
  3 
 / 
4 
<b>Output:</b>

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
</pre>
<p></p>

<p><b>Note:</b>
The height of binary tree is in the range of [1, 10].
</p>

**Companies**:  
[Uber](https://leetcode.com/company/uber), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/print-binary-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int depth, col;
    int d(TreeNode* root){
        if (!root) return 0;
        int l = d(root->left), r = d(root->right);
        return max(l, r) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>> &ans, int row, int l, int r){
        if (!root) return;
        int mid = (l + r) / 2 ;
        ans[row][mid] = to_string(root->val);
        dfs(root->left, ans, row + 1, l, mid);
        dfs(root->right, ans, row + 1, mid + 1, r);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        depth = d(root), col = pow(2, depth) - 1;
        vector<vector<string>> ans(depth, vector<string> (col));
        
        dfs(root, ans, 0, 0, col);
        return ans;
    }
};
```
