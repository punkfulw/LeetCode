# [203. Remove Linked List Elements (Easy)](https://leetcode.com/problems/remove-linked-list-elements/)

<p>Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/removelinked-list.jpg">
<pre>
<strong>Input:</strong> head = [1,2,6,3,4,5,6], val = 6
<strong>Output:</strong> [1,2,3,4,5]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> head = [], val = 1
<strong>Output:</strong> []
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> head = [7,7,7,7], val = 7
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the list is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
  <li><code>1 &lt;= Node.val &lt;= 50</code></li>
  <li><code>0 &lt;= val &lt;= 50</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Remove Element (Easy)](https://leetcode.com/problems/remove-element/)
* [Delete Node in a Linked List (Easy)](https://leetcode.com/problems/delete-node-in-a-linked-list/)

## Solution 1. No memory leak

```cpp
// OJ: https://leetcode.com/problems/remove-linked-list-elements/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = new ListNode(-1), *ans = p, *q = head;
        p->next = head;
        while (q){
            while (q && q->val == val){
                auto d = q;
                q = q->next;
                delete d;
            }
            p->next = q;
            q = q ? q->next : q;
            p = p->next;
        }
        return ans->next;
    }
};
```
