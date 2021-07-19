# [25. Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)

<p>Given a linked list, reverse the nodes of a linked list <em>k</em> at a time and return its modified list.</p>

<p><em>k</em> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <em>k</em> then left-out nodes, in the end, should remain as it is.</p>

<p>You may&nbsp;not alter the values in the list's nodes, only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 3
<strong>Output:</strong> [3,2,1,4,5]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 1
<strong>Output:</strong> [1,2,3,4,5]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list&nbsp;is in the range <code>sz</code>.</li>
	<li><code>1 &lt;= sz &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:</strong> Can you solve the problem in O(1) extra memory space?

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [eBay](https://leetcode.com/company/ebay), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Swap Nodes in Pairs (Medium)](https://leetcode.com/problems/swap-nodes-in-pairs/)
* [Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        int cnt = 0;
        ListNode dummy(-1);
        dummy.next = head;
        while (head != NULL){
            cnt++;
            head = head->next;
        }
        ListNode* p = dummy.next;
        for (int i = 0; i < cnt/k; i++){
            ListNode* c = p, *nex = c->next, *pre;
            for (int j = 1; j < k; j++){
                ListNode* h = c;
                c = nex;
                nex = c->next;
                c->next = h;
            } 
            if (i == 0)
                dummy.next = c;
            else
                pre->next = c;
            p->next = nex;
            pre = p;
            p = p->next;
        }
        return dummy.next;
    }
};
```
