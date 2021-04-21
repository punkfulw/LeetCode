# [1725. Number Of Rectangles That Can Form The Largest Square (Easy)](https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/)

<p>You are given an array <code>rectangles</code> where <code>rectangles[i] = [li, wi]</code> represents the <code>i​​​​​<sup>​​​​​​th</sup>​​​​</code> rectangle of length <code>li</code> and width <code>wi</code>.</p>

<p>You can cut the <code>i​​​​​<sup>​​​​​​th</sup>​​​​</code> rectangle to form a square with a side length of <code>k</code> if both <code>k <= li</code> and <code>k <= wi</code>. For example, 
  if you have a rectangle <code>[4,6]</code>, you can cut it to get a square with a side length of at most <code>4</code>.</p>

<p>Let <code>maxLen</code> be the side length of the <b>largest</b> square you can obtain from any of the given rectangles.</p>

<p>Return <em>the <b>number</b> of rectangles that can make a square with a side length of <code>maxLen</code>.</em></p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> rectangles = [[5,8],[3,9],[5,12],[16,5]]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The largest squares you can get from each rectangle are of lengths [5,3,5,5].
The largest possible square is of length 5, and you can get it out of 3 rectangles.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> rectangles = [[2,3],[3,7],[4,3],[3,7]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rectangles.length &lt;= 1000</code></li>
	<li><code>rectangles[i].length == 2</code></li>
  <li><code>1 &lt;= li, wi &lt;= 10​​​​​<sup>​​​​​​9</sup>​​​​</code></li>
  <li><code>li != wi</code></li>
</ul>




**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max {};
        int ans {};
        int size = rectangles.size();
        vector<int> len (size, 0);
        
        for (int i = 0; i < size; i++){
            len[i] = min(rectangles[i].at(0), rectangles[i].at(1));
            if (len[i] > max)
                max = len[i];
        }
        
        for (int i = 0; i < size; i++){
            if (len[i] == max)
                ans++;
        }
        return ans;
    }
};
```
