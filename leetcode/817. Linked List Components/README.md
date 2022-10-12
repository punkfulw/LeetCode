# [817. Linked List Components (Medium)](https://leetcode.com/problems/linked-list-components/)

<p>We are given&nbsp;<code>head</code>,&nbsp;the head node of a linked list containing&nbsp;<strong>unique integer values</strong>.</p>

<p>We are also given the list&nbsp;<code>G</code>, a subset of the values in the linked list.</p>

<p>Return the number of connected components in <code>G</code>, where two values are connected if they appear consecutively in the linked list.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 
head: 0-&gt;1-&gt;2-&gt;3
G = [0, 1, 3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 
head: 0-&gt;1-&gt;2-&gt;3-&gt;4
G = [0, 3, 1, 4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
</pre>

<p><strong>Note: </strong></p>

<ul>
	<li>If&nbsp;<code>N</code>&nbsp;is the&nbsp;length of the linked list given by&nbsp;<code>head</code>,&nbsp;<code>1 &lt;= N &lt;= 10000</code>.</li>
	<li>The value of each node in the linked list will be in the range<code> [0, N - 1]</code>.</li>
	<li><code>1 &lt;= G.length &lt;= 10000</code>.</li>
	<li><code>G</code> is a subset of all values in the linked list.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/linked-list-components/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Union_Find{
public:
    int parent[10001];
    
    Union_Find() {
        for (int i = 0; i < 10001; i++)
            parent[i] = i;
    }
    
    int find(int x){
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    void union_node(int a, int b){
        int pa = find(a), pb = find(b);
        if (pa < pb)
            parent[pb] = pa;
        else
            parent[pa] = pb;
    }
    
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        Union_Find uf;
        int pre = -1, cnt = 0, app[10001] = {};

        for (auto &i: nums)
            app[i] = 1;

        while (head){
            int cur = head->val;
            if (!app[cur])
                pre = -1;
            else {
                if (pre == -1)
                    pre = uf.find(cur);
                else
                    uf.union_node(pre, cur);
            }
            head = head->next;
            cnt++;
        }
        
        int ans = 0;
        for (int i = 0; i < cnt; i++)
            if (app[i] && uf.parent[i] == i)
                ans++;
        return ans;
    }
};
```

## Solution s. Set

```cpp
// OJ: https://leetcode.com/problems/linked-list-components/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;
        
        while (head){
            while (head && set.find(head->val) == set.end())
                head = head->next;
            if (!head)
                break;
            ans++;
            while (head && set.find(head->val) != set.end())
                head = head->next;
        }
        return ans;
    }
};
```
