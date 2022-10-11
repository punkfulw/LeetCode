# [572. Subtree of Another Tree (Easy)](https://leetcode.com/problems/subtree-of-another-tree/)

<p>Given two <strong>non-empty</strong> binary trees <b>s</b> and <b>t</b>, check whether tree <b>t</b> has exactly the same structure and node values with a subtree of <b>s</b>. A subtree of <b>s</b> is a tree consists of a node in <b>s</b> and all of this node's descendants. The tree <b>s</b> could also be considered as a subtree of itself.</p>

<p><b>Example 1:</b><br>
Given tree s:</p>

<pre>     3
    / \
   4   5
  / \
 1   2
</pre>
Given tree t:

<pre>   4 
  / \
 1   2
</pre>
Return <b>true</b>, because t has the same structure and node values with a subtree of s.

<p>&nbsp;</p>

<p><b>Example 2:</b><br>
Given tree s:</p>

<pre>     3
    / \
   4   5
  / \
 1   2
    /
   0
</pre>
Given tree t:

<pre>   4
  / \
 1   2
</pre>
Return <b>false</b>.

<p>&nbsp;</p>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Count Univalue Subtrees (Medium)](https://leetcode.com/problems/count-univalue-subtrees/)
* [Most Frequent Subtree Sum (Medium)](https://leetcode.com/problems/most-frequent-subtree-sum/)

# Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-unsorted-continuous-subarray
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(H) 
class Solution {
public:
    bool check(TreeNode* root, TreeNode* sub){
        if (!root || !sub){
            if (!root && !sub)
                return true;
            return false;
        }
        if (root->val != sub->val)
            return false;
        return check(root->left, sub->left) && check(root->right, sub->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
            return false;
        if (root->val == subRoot->val && check(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
```
