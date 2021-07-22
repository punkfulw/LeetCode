# [838. Push Dominoes (Medium)](https://leetcode.com/problems/push-dominoes/)

<p>There are <code>n</code> dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.</p>

<p>After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.</p>



<p>You are given a string <code>dominoes</code> representing the initial state where:.</p>

<ol>
	<li><code>dominoes[i] = 'L'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the left,</li>
	<li><code>dominoes[i] = 'R'</code>, if the <code>i<sup>th</sup></code> domino has been pushed to the right, and</li>
  <li><code>dominoes[i] = '.'</code>, if the <code>i<sup>th</sup></code> domino has not been pushed.</li>
</ol>


<p>Return<em> a string representing the final state.</em></p>



<p><strong>Example 1:</strong></p>
<pre>
<strong>Input: </strong>dominoes = "RR.L"
<strong>Output: </strong>"RR.L"
<strong>Explanation: </strong>The first domino expends no additional force on the second domino.
</pre>

<p><strong>Example 2:</strong></p>
<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png" style="height: 160px;"></p>
<pre>
<strong>Input: </strong>dominoes = ".L.R...LR..L.."
<strong>Output: </strong>"LL.RR.LLRRLL.."
</pre>

<p><strong>Constraints:</strong></p>

<ol>
  <li><code>n == dominoes.length</code></li>
	<li><code>0 &lt;= n&nbsp;&lt;= 10^5</code></li>
  <li><code>dominoes[i]</code> is either&nbsp;<code>'L'</code>, <code>'R'</code> and <code>'.'</code></li>
</ol>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/push-dominoes/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/push-dominoes/discuss/132332/JavaC%2B%2BPython-Two-Pointers
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string pushDominoes(string d) {
        d = "L" + d + "R";
        string ans;
        for (int i = 0, j = 1; j < d.size(); j++){
            if (d[j] == '.') continue;
            if (i > 0)
                ans += d[i];
            int mid = j - i - 1;
            if (d[i] == d[j])
                ans += string(mid, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                ans += string(mid, '.');
            else
                ans += string(mid/2, d[i]) + string(mid%2, '.') + string(mid/2, d[j]);
            i = j;
        }
        return ans;
    }
};
```
