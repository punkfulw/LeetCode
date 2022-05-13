# [117. Populating Next Right Pointers in Each Node II (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

<p>Given a binary tree</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/02/15/117_sample.png" style="width: 640px; height: 218px;"></p>

<pre><strong>Input:</strong> root = [1,2,3,4,5,null,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,7,#]
<strong>Explanation: </strong>Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the given tree is less than <code>6000</code>.</li>
	<li><code>-100&nbsp;&lt;= node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Populating Next Right Pointers in Each Node (Medium)](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(Q) 
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root) return root;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                auto cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                if (i == n - 1) cur->next = NULL;
                else cur->next = q.front();
            }
        }
        return root;
    }
};
```

## Solution 1. -py

```python3
# OJ: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
# Author: github.com/punkfulw
# Time: O(N)
# Space: O(Q)
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        q = []
        if (root == None):
            return root
        q.append(root)
        while len(q):
            n = len(q)
            for i in range(n):
                cur = q[0]
                q.pop(0)

                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)
                if i == n - 1:
                    cur.next = None
                else:
                    cur.next = q[0]
        return root
```
