# [23. Merge k Sorted Lists (Hard)](https://leetcode.com/problems/merge-k-sorted-lists/)

<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10^4</code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10^4 &lt;= lists[i][j] &lt;= 10^4</code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> won't exceed <code>10^4</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [ByteDance](https://leetcode.com/company/bytedance), [Yandex](https://leetcode.com/company/yandex), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [VMware](https://leetcode.com/company/vmware), [Bloomberg](https://leetcode.com/company/bloomberg), [eBay](https://leetcode.com/company/ebay), [tiktok](https://leetcode.com/company/tiktok), [Indeed](https://leetcode.com/company/indeed), [Oracle](https://leetcode.com/company/oracle), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Qualtrics](https://leetcode.com/company/qualtrics), [Sprinklr](https://leetcode.com/company/sprinklr), [Cruise Automation](https://leetcode.com/company/cruise-automation)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Merge Sort](https://leetcode.com/tag/merge-sort/)

**Similar Questions**:
* [Merge Two Sorted Lists (Easy)](https://leetcode.com/problems/merge-two-sorted-lists/)
* [Ugly Number II (Medium)](https://leetcode.com/problems/ugly-number-ii/)


## Solution 1. Merge Sort

```cpp
// OJ: https://leetcode.com/problems/merge-k-sorted-lists/
// Author: github.com/punkfulw
// Time: O(NlogK)
// Space: O(N)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        while (lists.size() > 1){
            int n = lists.size();
            vector<ListNode*> cur;
            for (int i = 0; i < n - 1; i += 2){
                ListNode* dummy = new ListNode(0), *head = dummy, *l1 = lists[i], *l2 = lists[i + 1];
                while (l1 && l2){
                    if (l1->val < l2->val){
                        head->next = l1;
                        l1 = l1->next;
                    }
                    else {
                        head->next = l2;
                        l2 = l2->next;
                    }
                    head = head->next;
                }
                if (l1)
                    head->next = l1;
                else
                    head->next = l2;
                head = dummy->next;
                delete(dummy);
                cur.push_back(head);
            }
            if (n % 2)
                cur.push_back(lists.back());
            lists = cur;
        }
        
        return lists[0];
    }
};

```
