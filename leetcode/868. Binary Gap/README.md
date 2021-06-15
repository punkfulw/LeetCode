# [868. Binary Gap (Easy)](https://leetcode.com/problems/binary-gap/)

<p>Given a positive&nbsp;integer <code>n</code>, find and return <em>the <b>longest distance</b> between two <b>adjacent</b> </em><code>1</code><em>'s in the binary representation of </em><code>n</code>.</p>

<p><em>If there aren't two consecutive </em><code>1</code><em>'s, return </em><font face="monospace"><code>0</code></font>.</p>

<p>Two <code>1</code>'s are <b>adjacent</b>if there are only <code>0</code>'s separating them (possibly no 0's). 
  The <b>distance</b> between two <code>1</code>'s is the absolute difference between their bit positions. For example, the two <code>1</code>'s in <code>"1001"</code> have a distance of 3.</p>
<p>&nbsp;</p>

<div>
<div>
<div>
<ul>
</ul>
</div>
</div>
</div>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">22</span>
<strong>Output: </strong>2
<strong>Explanation: </strong>
22 in binary is "10110".
In the binary representation of 22, there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, which is 2.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">5</span>
<strong>Output: </strong><span id="example-output-2">2</span>
<strong>Explanation: </strong>
5 in binary is "101".
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">6</span>
<strong>Output: </strong><span id="example-output-3">1</span>
<strong>Explanation: </strong>
6 in binary is "110".
</pre>

<div>
<p><strong>Example 4:</strong></p>

<pre><strong>Input: </strong><span id="example-input-4-1">8</span>
<strong>Output: </strong><span id="example-output-4">0</span>
<strong>Explanation: </strong>
8 in binary is "1000".
There aren't any consecutive pairs of 1's in the binary representation of 8, so we return 0.
</pre>

<p>&nbsp;</p>

<div>
<div>
<div>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= N &lt;= 10<sup>9</sup></code></li>
</ul>
</div>
</div>
</div>
</div>
</div>
</div>
</div>


**Companies**:  
[Twitter](https://leetcode.com/company/twitter), [eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int n) {
        int index = 1;
        int ans = 0, cur = 0, pre = -1;
        while (index <= n){
            if (index & n){
                if (pre == -1){
                    pre = cur;
                    continue;
                }
                ans = max(ans, cur-pre);
                pre = cur;
            }
            index <<= 1;
            cur++;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/binary-gap/discuss/149835/C%2B%2BJavaPython-Dividing-by-2
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        for (int d = -32; N; N /= 2, d++)
            if (N % 2) res = max(res, d), d = 0;
        return res;
    }
};
```
