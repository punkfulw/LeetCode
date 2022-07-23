# [61. Rotate List (Medium)](https://leetcode.com/problems/rotate-list/)

<p>Given the <code>head</code> of a linked&nbsp;list, rotate the list to the right by <code>k</code> places.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px; height: 191px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [4,5,1,2,3]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;">
<pre><strong>Input:</strong> head = [0,1,2], k = 4
<strong>Output:</strong> [2,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 500]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Rotate Array (Medium)](https://leetcode.com/problems/rotate-array/)
* [Split Linked List in Parts (Medium)](https://leetcode.com/problems/split-linked-list-in-parts/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rotate-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return NULL;
        int n = 1;
        ListNode *dummy = new ListNode(0), *p = dummy, *tmp = head;
        dummy->next = head;
        while (head->next){
            n++;
            head = head->next;
        }
        head->next = dummy->next;
        k %= n;
        int step = n - k;
        while (step--)
            p = p->next;
        dummy->next = p->next;
        p->next = NULL;
        
        return dummy->next;
    }
};
```

