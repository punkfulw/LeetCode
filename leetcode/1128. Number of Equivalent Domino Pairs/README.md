# [1128. Number of Equivalent Domino Pairs (Easy)](https://leetcode.com/problems/number-of-equivalent-domino-pairs/)

<p>Given a list of <code>dominoes</code>,&nbsp;<code>dominoes[i] = [a, b]</code>&nbsp;is <em>equivalent</em> to <code>dominoes[j] = [c, d]</code>&nbsp;if and only if either (<code>a==c</code> and <code>b==d</code>), or (<code>a==d</code> and <code>b==c</code>) - that is, one domino can be rotated to be equal to another domino.</p>

<p>Return the number of pairs <code>(i, j)</code> for which <code>0 &lt;= i &lt; j &lt; dominoes.length</code>, and&nbsp;<code>dominoes[i]</code> is equivalent to <code>dominoes[j]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 40000</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        int n = dom.size(), ans = 0, type[10][10] = {};
        for (auto d: dom){
            if (d[0] > d[1])
                swap(d[0], d[1]);
            type[d[0]][d[1]]++;
        }
        
        for (int i = 1; i < 10; i++){
            for (int j = 1; j < 10; j++){
                int num = type[i][j];
                ans += (num - 1) * num / 2;
            }
        }
        return ans;
    }
};
```
