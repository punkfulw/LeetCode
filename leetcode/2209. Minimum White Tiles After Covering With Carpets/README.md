# [2209. Minimum White Tiles After Covering With Carpets (Hard)](https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/)

<p>You are given a <strong>0-indexed binary</strong> string <code>floor</code>, which represents the colors of tiles on a floor:</p>

<ul>
	<li><code>floor[i] = '0'</code> denotes that the <code>i<sup>th</sup></code> tile of the floor is colored <strong>black</strong>.</li>
	<li>On the other hand, <code>floor[i] = '1'</code> denotes that the <code>i<sup>th</sup></code> tile of the floor is colored <strong>white</strong>.</li>
</ul>

<p>You are also given <code>numCarpets</code> and <code>carpetLen</code>. You have <code>numCarpets</code> <strong>black</strong> carpets, each of length <code>carpetLen</code> tiles. Cover the tiles with the given carpets such that the number of <strong>white</strong> tiles still visible is <strong>minimum</strong>. Carpets may overlap one another.</p>

<p>Return <em>the <strong>minimum</strong> number of white tiles still visible.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex1-1.png" style="width: 400px; height: 73px;">
<pre><strong>Input:</strong> floor = "10110101", numCarpets = 2, carpetLen = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The figure above shows one way of covering the tiles with the carpets such that only 2 white tiles are visible.
No other way of covering the tiles with the carpets can leave less than 2 white tiles visible.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/02/10/ex2.png" style="width: 353px; height: 123px;">
<pre><strong>Input:</strong> floor = "11111", numCarpets = 2, carpetLen = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
The figure above shows one way of covering the tiles with the carpets such that no white tiles are visible.
Note that the carpets are able to overlap one another.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= carpetLen &lt;= floor.length &lt;= 1000</code></li>
	<li><code>floor[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>1 &lt;= numCarpets &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Edit Distance (Hard)](https://leetcode.com/problems/edit-distance/)

## Solution 1. Sliding Window + DP

Count the white floor first.

If floor <= num of Carpet * carpet Lens, all floor is coverable.

Using Slding window to find to the maximum coverd part.

Convert this zone into all '0'

continue the opration until white <= 0 or there's no more carpet

```cpp
// OJ: https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
// Author: github.com/punkfulw
// Time: O(N * C) floor * number of carpets
// Space: O(N * C)
class Solution {
public:
    int minimumWhiteTiles(string f, int numC, int cL) {
        
        int white = 0;
        for (auto c: f)
            if (c == '1')
                white++;
        
        if (f.size() <= numC * cL)
            return 0;

        while (numC-- && white > 0)
        {
            int cur = 0, start, end, zone = 0;
            zone = 0;
            for (int i = 0; i < f.size(); i++)
            {
                if (f[i] == '1')
                    cur++;
                if (i >= cL - 1)
                {
                    if (cur > zone)
                    {
                        zone = cur;
                        start = i - cL + 1;
                        end = i;
                    }
                }
                if (i >= cL - 1 && f[i - cL + 1] == '1')
                    cur--;
            }
            for (int i = start; i <= end; i++)
                f[i] = '0';
            white -= zone;
        }
        return max(white, 0);
    }
};
```

## Disucss

https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/discuss/1863879
