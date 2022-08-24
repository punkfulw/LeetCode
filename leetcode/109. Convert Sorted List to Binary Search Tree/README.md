# [109. Convert Sorted List to Binary Search Tree (Medium)](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

<p>Given the <code>head</code> of a singly linked list where elements are <strong>sorted in ascending order</strong>, convert it to a height balanced BST.</p>

<p>For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of <em>every</em> node never differ by more than 1.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/17/linked.jpg" style="width: 600px; height: 466px;">
<pre><strong>Input:</strong> head = [-10,-3,0,5,9]
<strong>Output:</strong> [0,-3,9,-10,null,5]
<strong>Explanation:</strong> One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [0]
<strong>Output:</strong> [0]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [1,3]
<strong>Output:</strong> [3,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in <code>head</code> is in the range <code>[0, 2 * 10<sup>4</sup>]</code>.</li>
	<li><code>-10^5 &lt;= Node.val &lt;= 10^5</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Oracle](https://leetcode.com/company/oracle)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Convert Sorted Array to Binary Search Tree (Easy)](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)


## Solution 1. Fast Slow Pointers

```cpp
// OJ: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* slow = head, *fast = head, *tail, *pre = head;
        while (fast && fast->next){
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        tail = slow->next;
        pre->next = NULL;
        TreeNode* root= new TreeNode(slow->val);
        if (slow != head)
            root->left = sortedListToBST(head);
        root->right = sortedListToBST(tail);
        return root;
    }
};
```
