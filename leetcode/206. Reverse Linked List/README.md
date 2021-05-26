# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
  <li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p><b>Follow up:</b> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Apple](https://leetcode.com/company/apple), [Mathworks](https://leetcode.com/company/mathworks), [Bloomberg](https://leetcode.com/company/bloomberg), [Adobe](https://leetcode.com/company/adobe), [Amazon](https://leetcode.com/company/amazon), [Yandex](https://leetcode.com/company/yandex), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Google](https://leetcode.com/company/google), [Baidu](https://leetcode.com/company/baidu), [Nvidia](https://leetcode.com/company/nvidia), [Expedia](https://leetcode.com/company/expedia), [Yahoo](https://leetcode.com/company/yahoo), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Reverse Linked List II (Medium)](https://leetcode.com/problems/reverse-linked-list-ii/)
* [Binary Tree Upside Down (Medium)](https://leetcode.com/problems/binary-tree-upside-down/)
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL, *cur = NULL;
        while (head != NULL){
            pre = cur;
            cur = head;
            head = head->next;
            cur->next = pre;
        }
        return cur;
    }
};
```
