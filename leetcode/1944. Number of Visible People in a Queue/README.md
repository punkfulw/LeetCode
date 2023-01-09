# [1944. Number of Visible People in a Queue (Hard)](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)

<p>There are <code>n</code> people standing in a queue, and they numbered from <code>0</code> to <code>n - 1</code> in <strong>left to right</strong> order. You are given an array <code>heights</code> of <strong>distinct</strong> integers where <code>heights[i]</code> represents the height of the <code>i<sup>th</sup></code> person.</p>

<p>A person can <strong>see</strong> another person to their right in the queue if everybody in between is <strong>shorter</strong> than both of them. More formally, the <code>i<sup>th</sup></code> person can see the <code>j<sup>th</sup></code> person if <code>i &lt; j</code> and <code>min(heights[i], heights[j]) &gt; max(heights[i+1], heights[i+2], ..., heights[j-1])</code>.</p>

<p>Return <em>an array </em><code>answer</code><em> of length </em><code>n</code><em> where </em><code>answer[i]</code><em> is the <strong>number of people</strong> the </em><code>i<sup>th</sup></code><em> person can <strong>see</strong> to their right in the queue</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/05/29/queue-plane.jpg" style="width: 600px; height: 247px;"></p>

<pre><strong>Input:</strong> heights = [10,6,8,5,11,9]
<strong>Output:</strong> [3,1,2,1,1,0]
<strong>Explanation:</strong>
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [5,1,2,3,10]
<strong>Output:</strong> [4,1,1,1,0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == heights.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>5</sup></code></li>
	<li>All the values of <code>heights</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Buildings With an Ocean View (Medium)](https://leetcode.com/problems/buildings-with-an-ocean-view/)

## Solution 1. Monostack

```cpp
// OJ: https://leetcode.com/problems/number-of-visible-people-in-a-queue/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> stk;
        heights.push_back(INT_MAX);
        stk.push(n);
        
        for (int i = n - 1; i >= 0; i--){
            int cnt = 0;
            while (!stk.empty() && heights[i] >= heights[stk.top()]){
                cnt++;
                stk.pop();
            }
            cnt += stk.top() == n ? 0 : 1;
            ans[i] = cnt;
            stk.push(i);
        }
        return ans;
    }
};
```
