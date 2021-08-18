# [725. Split Linked List in Parts (Medium)](https://leetcode.com/problems/split-linked-list-in-parts/)

<p>Given the <code>head</code> of a singly linked list and an integer <code>k</code>, split the linked list into <code>k</code> consecutive linked list parts.</p>

<p>The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.</p>

<p>The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.</p>

<p>Return <em>an array of the <code>k</code> parts.</em></p>

<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split1-lc.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> head = [1,2,3], k = 5
<strong>Output:</strong> [[1],[2],[3],[],[]]
<strong>Explanation:</strong> 
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/13/split2-lc.jpg" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> head = [1,2,3,4,5,6,7,8,9,10], k = 3
<strong>Output:</strong> [[1,2,3,4],[5,6,7],[8,9,10]]
<strong>Explanation:</strong> 
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the list is in the range <code>[0, 1000]</code>.</li>
  <li><code>0 &lt;=  Node.val &lt;= 1000</code></li>
  <li><code>1 &lt;= k &lt;= 50</code></li>
</ul>



**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/split-linked-list-in-parts/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = ListSize(head);
        vector<ListNode*> ans(k, NULL);
        int n = cnt / k, remain = cnt % k;
        ListNode* node = head, *pre;
        
        for (int i = 0; node && i < k; i++, remain--){
            ans[i] = node;
            for (int j = 0; j < n + (remain > 0); j++){
                pre = node;
                node = node->next;
            }
            pre->next = NULL;
        }
        
        return ans;
    }
    
    int ListSize(ListNode* head){
        int cnt = 0;
        while (head != NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};
```
