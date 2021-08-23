# [653. Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

<p>Given the <code>root</code> of a Binary Search Tree and a target number <code>k</code>, 
  return <em>.<code>true</code> if there exist two elements in the BST such that their sum is equal to the given target.</em></p>



<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 9
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 28
<strong>Output:</strong> false
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> root = [2,1,3], k = 4
<strong>Output:</strong> true
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
  <li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
  <li><code>root</code> is guaranteed to be a <b>valid</b> binary search tree.</li>
  <li><code>-10<sup>5</sup> &lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)

## Solution 1. dfs

```cpp
// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        return findsum(root, k, mp);
    }
    bool findsum(TreeNode* root, int k, unordered_map<int, int>& mp){
        if (!root) return false;
        int cur = root->val;
        if (mp[cur]) return true;
        mp[k - cur] = 1;
        return findsum(root->left, k, mp) || findsum(root->right, k, mp);
    }
};
```

## Solution 2. queue

```cpp
// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            auto node = q.front(); q.pop();
            int num = node->val;
            if (mp[num]) return true;
            mp[k-num] = 1;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
};
```
