# [143. Reorder List (Medium)](https://leetcode.com/problems/reorder-list/)

<p>You are given the head of a singly linked-list. The list can be represented as:</p>

<pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p><em>Reorder the list to be on the following form:</em></p>

<pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
</pre>

<p>You may not modify the values in the list's nodes. Only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,4,2,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,5,2,4,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Delete the Middle Node of a Linked List (Medium)](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reorder-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        vector<ListNode*> nodes;
        while (tmp){
            n++;
            nodes.push_back(tmp);
            tmp = tmp->next;
        }
        int i = 0, j = n - 1;
        for (; i < j; i++, j--){
            nodes[i]->next = nodes[j];
            if (i == j - 1)
                nodes[j]->next = NULL;
            else
                nodes[j]->next = nodes[i + 1];
        }
        if (i == j)
            nodes[i]->next = NULL;
        return ;
    }
};
```

