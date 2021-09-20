# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

<p>Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list1.jpg">
<pre>
<strong>Input:</strong> head = [1,1,2]
<strong>Output:</strong> [1,2]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/04/list2.jpg">
<pre>
<strong>Input:</strong> head = [1,1,2,3,3]
<strong>Output:</strong> [1,2,3]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the list is in the range <code>[0, 300].</code></li>
  <li><code>-100 &lt;= Node.val &lt;= 100</code></li>
  <li><code>The list is guaranteed to be sorted in ascending order.</code></li>
</ul>



**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        while (p){
            auto q = p->next;
            while (q && p->val == q->val){
                p->next = q->next;
                delete q;
                q = p->next;
            }
            p = p->next;
        }
        return head;
    }
};
```

