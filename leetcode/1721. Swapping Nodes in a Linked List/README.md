# [1721. Swapping Nodes in a Linked List (Medium)](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

<p>You are given the <code>head</code> of a linked list, and an integer <code>k</code>.</p>

<p>Return <em>the head of the linked list after <strong>swapping</strong> the values of the </em><code>k<sup>th</sup></code> <em>node from the beginning and the </em><code>k<sup>th</sup></code> <em>node from the end (the list is <strong>1-indexed</strong>).</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg" style="width: 722px; height: 202px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [1,4,3,2,5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [7,9,6,6,7,8,3,0,9,5], k = 5
<strong>Output:</strong> [7,9,6,6,8,7,3,0,9,5]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [1,2], k = 1
<strong>Output:</strong> [2,1]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3], k = 2
<strong>Output:</strong> [1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

**Similar Questions**:
* [Remove Nth Node From End of List (Medium)](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
* [Swap Nodes in Pairs (Medium)](https://leetcode.com/problems/swap-nodes-in-pairs/)
* [Reverse Nodes in k-Group (Hard)](https://leetcode.com/problems/reverse-nodes-in-k-group/)

## Solution 1. swap entire node

```cpp
// OJ: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 1;
        ListNode dummy(0);
        dummy.next = head;
        while (head->next){
            head = head->next;
            cnt++;
        }
        int p = cnt-k+1;
        if (p == k)
            return dummy.next;
        if (p < k)
            swap(p, k);
        head = dummy.next;
        int num = 1;
        ListNode* ff = &dummy, *bf;
        while (head->next){
            if (num == k-1)
                ff = head;
            else if (num == p-1)
                bf = head;
            num++;
            head = head->next;
        }
        ListNode* f = ff->next;
        ListNode* b = bf->next;
        ff->next = b;
        ff = b->next;
        if (abs(p-k) > 1){
            b->next = f->next;
            bf->next = f; 
        }
        else
            b->next = f;
        f->next = ff;

        return dummy.next;
    }
};
```

## Solution 1. only swap val

```cpp
// OJ: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009800/C%2B%2BJP3-One-Pass
// Time: O(N)
// Space: O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *n1 = NULL, *n2 = NULL;
        for (auto p = head; p != NULL; p = p->next){
            n2 = n2 == NULL ? NULL : n2->next;
            if (--k == 0){
                n1 = p;
                n2 = head;
            }
        }
        swap(n1->val, n2->val);
        return head;
    }
};
```
