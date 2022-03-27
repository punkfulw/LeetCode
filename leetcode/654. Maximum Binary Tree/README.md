# [654. Maximum Binary Tree (Medium)](https://leetcode.com/problems/maximum-binary-tree/)

<p>
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
</p><ol>
<li>The root is the maximum number in the array. </li>
<li>The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.</li>
<li>The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.</li> 
</ol>
<p></p>

<p>
  Return <em>the <b>maximum binary tree</b> built from </em><code>nums</code>.
</p>

<p><b>Example 1:</b><br>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/tree1.jpg">
</p><pre><b>Input:</b> nums = [3,2,1,6,0,5]
<b>Output:</b> [6,3,5,null,2,0,null,null,1]
<b>Explaination:</b> The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
</pre>


<p><b>Example 2:</b><br>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/tree2.jpg">
</p><pre><b>Input:</b> nums = [3,2,1]
<b>Output:</b> [3,null,2,null,1]
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-binary-tree/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return NULL;
        int pos = start;
        for (int i = start; i <= end; i++)
            if (nums[i] > nums[pos])
                pos = i;  
        TreeNode* root = new TreeNode(nums[pos]);
        root->left = solve(nums, start, pos - 1);
        root->right = solve(nums, pos + 1, end);
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
```
