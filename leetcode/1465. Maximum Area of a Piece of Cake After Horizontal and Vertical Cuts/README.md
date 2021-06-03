# [1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts (Medium)](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)

<p>Given a rectangular cake with height <code>h</code> and width <code>w</code>, and two arrays of integers <code>horizontalCuts</code> and <code>verticalCuts</code> 
  where <code>horizontalCuts[i]</code> is the distance from the top of the rectangular cake to the <code>ith</code> horizontal cut and similarly,
  <code>verticalCuts[j]</code> is the distance from the left of the rectangular cake to the <code>jth</code> vertical cut.</p>

<p><em>Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays <code>horizontalCuts</code> and <code>verticalCuts</code></em>. 
  Since the answer can be a huge number, return this modulo 10^9 + 7.</p>


<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_2.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. 
After you cut the cake, the green piece of cake has the maximum area.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/05/14/leetcode_max_area_3.png" style="width: 600px; height: 150px;">
<pre>
<strong>Input:</strong> h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The figure above represents the given rectangular cake. 
Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
<strong>Output:</strong> 9
</pre>



<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= h, w &lt;= 10<sup>9</sup></code></li>
  <li><code>1 &lt;= horizontalCuts.length &lt;= min(h, 10^5)</code></li>
  <li><code>1 &lt;= verticalCuts.length &lt;= min(h, 10^5)</code></li>
  <li><code>1 &lt;= horizontalCuts[i] &lt; h</code></li>
  <li><code>1 &lt;= verticalCuts[i] &lt; w</code></li>
  <li>It is guaranteed that all elements in <code>horizontalCuts</code> are distinct.</li>
  <li>It is guaranteed that all elements in <code>verticalCuts</code> are distinct.</li>
</ul>



**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int v_size = verticalCuts.size(), h_size = horizontalCuts.size();
        auto v = max(verticalCuts[0], w - verticalCuts[v_size-1]);
        auto hi = max(horizontalCuts[0], h - horizontalCuts[h_size-1]);
        
        for (int i = 1; i < v_size; i++){
            v = max(v, verticalCuts[i]-verticalCuts[i-1]);
        }
        for (int i = 1; i < h_size; i++){
            hi = max(hi, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        cout << v << " " << hi;
        return (long)v * hi % 1000000007;
    }
};

```

