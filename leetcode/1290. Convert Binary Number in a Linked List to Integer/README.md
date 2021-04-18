# [1290. Convert Binary Number in a Linked List to Integer (Easy)](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/)

<p>Given <code>head</code> which is a reference node to&nbsp;a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.</p>

<p>Return the <em>decimal value</em> of the number in the linked list.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/12/05/graph-1.png" style="width: 426px; height: 108px;">
<pre><strong>Input:</strong> head = [1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> (101) in base 2 = (5) in base 10
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [0]
<strong>Output:</strong> 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
<strong>Output:</strong> 18880
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> head = [0,0]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The Linked List is not empty.</li>
	<li>Number of nodes&nbsp;will not exceed <code>30</code>.</li>
	<li>Each node's value is either&nbsp;<code>0</code> or <code>1</code>.</li>
</ul>

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.  

```cpp
// OJ: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* index = head;
        vector<int> nums;
        while (index != nullptr){
            nums.push_back(index->val);
            index = index->next;
        }
        int ans {};
        for (int i = 0; i < nums.size(); i++){
            ans += nums[i] * pow(2, nums.size()-i-1);
        }
        return ans;
    }
};
```

## Solution 2.  Using leftshift to accumulate ans;

```cpp
// OJ: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans {};
        ListNode* index = head;
        while (index){
            ans = (ans << 1) + index -> val;
            index = index -> next;
        }
        return ans;
    }
};
```
