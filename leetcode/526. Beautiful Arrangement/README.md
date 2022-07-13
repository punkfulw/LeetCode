# [526. Beautiful Arrangement (Medium)](https://leetcode.com/problems/beautiful-arrangement/)

<p>Suppose you have <code>n</code> integers labeled <code>1</code> through <code>n</code>. A permutation of those <code>n</code> integers <code>perm</code> (<strong>1-indexed</strong>) is considered a <strong>beautiful arrangement</strong> if for every <code>i</code> (<code>1 &lt;= i &lt;= n</code>), <strong>either</strong> of the following is true:</p>

<ul>
	<li><code>perm[i]</code> is divisible by <code>i</code>.</li>
	<li><code>i</code> is divisible by <code>perm[i]</code>.</li>
</ul>

<p>Given an integer <code>n</code>, return <em>the <strong>number</strong> of the <strong>beautiful arrangements</strong> that you can construct</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<b>Explanation:</b> 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 15</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Depth-first Search](https://leetcode.com/tag/depth-first-search/)

**Similar Questions**:
* [Beautiful Arrangement II (Medium)](https://leetcode.com/problems/beautiful-arrangement-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/beautiful-arrangement/
// Author: github.com/punkfulw
// Time: O(K) where K is the number of valid permuataions
// Space: O(N)
class Solution {
public:
    int ans = 0;
    void dfs(vector<int> &nums, int idx, int n){
        if (idx == n + 1){
            ans++;  
            return;
        }
        for (int i = 1; i <= n; i++){
            if (nums[i-1] != 0 || (idx % i != 0 && i % idx != 0))
                continue;
            nums[i-1] = idx;
            dfs(nums, idx + 1, n);
            nums[i-1] = 0;
        }
    }
    int countArrangement(int n) {
        vector<int> nums(n);
        dfs(nums, 1, n);
        return ans;
    }
};
```
