# [1046. Last Stone Weight (Easy)](https://leetcode.com/problems/last-stone-weight/)

<p>We have a collection of stones, each stone&nbsp;has a positive integer weight.</p>

<p>Each turn, we choose the two <strong>heaviest</strong>&nbsp;stones&nbsp;and smash them together.&nbsp; Suppose the stones have weights <code>x</code> and <code>y</code> with <code>x &lt;= y</code>.&nbsp; The result of this smash is:</p>

<ul>
	<li>If <code>x == y</code>, both stones are totally destroyed;</li>
	<li>If <code>x != y</code>, the stone of weight <code>x</code> is totally destroyed, and the stone of weight <code>y</code> has new weight <code>y-x</code>.</li>
</ul>

<p>At the end, there is at most 1 stone left.&nbsp; Return the weight of this stone (or 0 if there are no stones left.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[2,7,4,1,8,1]
<strong>Output: </strong>1
<strong>Explanation: </strong>
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= stones.length &lt;= 30</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 1000</code></li>
</ol>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            auto p1 = max_element(stones.begin(), stones.end());
            int a = *p1;
            stones.erase(p1);
            auto p2 = max_element(stones.begin(), stones.end());
            int b = *p2;
            stones.erase(p2);
            if (a != b)
                stones.push_back(abs(a-b));
        }
        return stones.size() == 0 ? 0 : stones[0];
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> q(begin(stones), end(stones));
      while (q.size() > 1) {
        auto w1 = q.top(); q.pop();
        auto w2 = q.top(); q.pop();
        if (w1 - w2 > 0) q.push(w1 - w2);
      }
      return q.empty() ? 0 : q.top();
    }
};
```

## Solution 3. 

```python3
# OJ: https://leetcode.com/problems/last-stone-weight/
# Author: github.com/punkfulw
# Time: O(NlogN)
# Space: O(1)
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        for i, s in enumerate(stones):
            stones[i] = -s
        heapify(stones)
        while len(stones) > 1:
            f, s = -heappop(stones), -heappop(stones)
            if f - s > 0:
                heappush(stones, s - f)
        if not stones:
            return 0
        return -stones[0]
            
```
