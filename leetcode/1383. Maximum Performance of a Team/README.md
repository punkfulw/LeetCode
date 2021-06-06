# [1383. Maximum Performance of a Team (Hard)](https://leetcode.com/problems/maximum-performance-of-a-team/)

<p>You are given two integers <code>n</code> and <code>k</code> and two integer arrays <code>speed</code> and <code>efficiency</code> both of length <code>n</code>. 
  There are <code>n</code> engineers numbered from <code>1</code> to <code>n</code>. 
  <code>speed[i]</code> and <code>efficiency[i]</code> represent the speed and efficiency of the <code>i<sup>th</sup></code> engineer respectively.</p>

<p>Choose <b>at most</b> <code>k</code> different engineers out of the <code>n</code> engineers to form a team with the maximum <b>performance</b>.</p>

<p>The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.</p>

<p>Return <em>the maximum performance of this team</em>. Since the answer can be a huge number, return it <b>modulo</b> <code>10<sup>9</sup> + 7</code>.</p>


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
<strong>Output:</strong> 60
<strong>Explanation:</strong> 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
<strong>Output:</strong> 68
<strong>Explanation:
</strong>This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) * min(5, 4, 7) = 68.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
<strong>Output:</strong> 72
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>speed.length == n</code></li>
	<li><code>efficiency.length == n</code></li>
	<li><code>1 &lt;= speed[i] &lt;= 10^5</code></li>
	<li><code>1 &lt;= efficiency[i] &lt;= 10^8</code></li>
	<li><code>1 &lt;= k &lt;= n</code></li>
</ul>

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/maximum-performance-of-a-team/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-performance-of-a-team/discuss/539687/JavaC%2B%2BPython-Priority-Queue
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i < n; i++)
            ess.emplace_back(efficiency[i], speed[i]);
        sort(ess.rbegin(), ess.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long sumS = 0, res = 0;
        for (auto [e, s]: ess){
            sumS += s;
            pq.push(s);
            if (pq.size() > k){
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res;
    }
};
```
