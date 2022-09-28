# [19. Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

<p>Given the <code>head</code> of a linked list, remove the <code>n<sup>th</sup></code> node from the end of the list and return its head.</p>

<p><strong>Follow up:</strong>&nbsp;Could you do this in one pass?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], n = 2
<strong>Output:</strong> [1,2,3,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [1], n = 1
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1,2], n = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>sz</code>.</li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)
* [Delete N Nodes After M Nodes of a Linked List (Easy)](https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/)


## Solution 1. delete node

```cpp
// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        
        int cnt = 1;
        for (auto p = head; p->next; p = p->next)
            cnt++;
        cnt -= n;
        if (cnt == 0){
            dummy.next = head->next;
            delete(head);
            return dummy.next;
        }
        for (auto p = head; p; p = p->next){
            if (cnt == 1){
                auto d = p->next;
                p->next = d->next;
                delete(d);
                break;
            }
            cnt--;
        }
        return head;
    }
};
```

## Solution 2. one pass

```cpp
// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/19.%20Remove%20Nth%20Node%20From%20End%20of%20List/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        while (n--) q = q->next;
        if (!q) return head->next;
        while (q->next) {
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return head;
    }
};
```

## Solution 3. one pass two pointer 2022.

```cpp
// OJ: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0), *fast = dummy, *slow = dummy;
        dummy->next = head;
        while (fast){
            fast = fast->next;
            if (n < 0)
                slow = slow->next;
            n--;
        }
        if (slow && slow->next)
            slow->next = slow->next->next;
        return dummy->next;
    }
};
```
