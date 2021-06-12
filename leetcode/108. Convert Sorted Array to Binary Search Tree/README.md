# [108. Convert Sorted Array to Binary Search Tree (Easy)](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)

<p>Given an integer array <code>nums</code> where the elements are sorted in <b>ascending order</b>, convert <em>it to a <b>height-balanced</b> binary search tree</em>.</p>

<p>A <b>height-balanced</b> binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.</p>

![image](https://assets.leetcode.com/uploads/2021/02/18/btree1.jpg)

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> nums = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> [0,-10,5,null,-3,null,9] is also accepted:
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree2.jpg" style="width: 600px; height: 150px;">
</pre>


<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/18/btree.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> nums = [1,3]
<strong>Output:</strong> [3,1]
<strong>Explanation:</strong> [1,3] and [3,1] are both a height-balanced BSTs.
</pre>

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
  <li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
  <li><code>nums</code> is sorted in a <b>strictly increasing</b> order.</li>
</ul>



**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)



## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        return helper(nums, 0, nums.size()-1, root);
    }
    TreeNode* helper(vector<int>& nums, int start, int end, TreeNode* root){
        if (start <= end){
            int m = (start + end) / 2;
            TreeNode* cur = new TreeNode(nums[m]);
            cur->left = helper(nums, start, m-1, root);
            cur->right = helper(nums, m+1, end, root);
            return cur;
        }
        return NULL;
    }
};
```

