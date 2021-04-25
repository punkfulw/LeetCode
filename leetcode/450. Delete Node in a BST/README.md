# [450. Delete Node in a BST (Medium)](https://leetcode.com/problems/delete-node-in-a-bst/)

<p>Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.</p>

<p>Basically, the deletion can be divided into two stages:
</p><ol>
<li>Search for a node to remove.</li>
<li>If the node is found, delete the node.</li>
</ol>
<p></p>

<p><b>Follow up:</b> Can you solve it with time complexity <code>O(height of tree)</code>?</p>

<p><strong>Example 1:</strong></p>

![image](https://github.com/punkfulw/LeetCode/blob/main/leetcode/450.%20Delete%20Node%20in%20a%20BST/del_node_1.jpg)
<pre>
<strong>Input: </strong>root = [5,3,6,2,4,null,7], key = 3
<strong>Output: </strong>[5,4,6,2,null,null,7]
<strong>Explanation: </strong>
Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
</pre>
![image](https://github.com/punkfulw/LeetCode/blob/main/leetcode/450.%20Delete%20Node%20in%20a%20BST/del_node_supp.jpg)
<pre></pre>


<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong> root = [5,3,6,2,4,null,7], key = 0
<strong>Output: </strong> [5,3,6,2,4,null,7]
<strong>Explanation: </strong>  The tree does not contain a node with value = 0.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong> root = [], key = 0
<strong>Output: </strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
  <li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
  <li>Each node has a <b>unique</b> value.</li>
  <li><code>root</code> is a valid binary search tree.</li>
  <li><code>-10<sup>5</sup> &lt;= key &lt;= 10<sup>5</sup></code></li>
</ul>




**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-node-in-a-bst/
// Author: github.com/punkfulw
// Time: O(H)
// Space: O(H)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if  (root == nullptr)
            return root;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else {
            if (!root->left && !root->right){
                delete(root);
                return nullptr;
            }           
            if (!root->left || !root->right){
                TreeNode* child = root->left ? root->left : root->right;
                delete(root);
                return child;
            }
            if (root->left && root->right){
                TreeNode** pre = &(root->right);
                TreeNode* temp = root->right;
                while (temp->left){
                    pre = &(temp->left);
                    temp = temp->left;
                }
                root->val = temp->val;;  
                *pre = deleteNode(*pre, temp->val);
            }
        }
        return root;
    }
};
```
