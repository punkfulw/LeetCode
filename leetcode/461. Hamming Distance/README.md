# [461. Hamming Distance (Easy)](https://leetcode.com/problems/hamming-distance/)

<p>The <a href="https://en.wikipedia.org/wiki/Hamming_distance" target="_blank">Hamming distance</a> between two integers is the number of positions at which the corresponding bits are different.</p>

<p>Given two integers <code>x</code> and <code>y</code>, return <em>the <b>Hamming distance</b> between them.</em></p>


<p><b>Example 1:</b>
</p><pre>
<b>Input:</b> x = 1, y = 4
<b>Output:</b> 2

<b>Explanation:</b>
1   (0 0 0 1)
4   (0 1 0 0)
.      ↑   ↑
The above arrows point to positions where the corresponding bits are different.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 &lt;= x, y &lt;= 2<sup>31</sup>-1</code></li>
</ul>


**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Number of 1 Bits (Easy)](https://leetcode.com/problems/number-of-1-bits/)
* [Total Hamming Distance (Medium)](https://leetcode.com/problems/total-hamming-distance/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/hamming-distance/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int xr = x ^ y;
        
        while (xr){
            if (xr%2 == 1)
                ans++;
            xr >>= 1;
        }
        return ans;
    }
};
```


