# [633. Sum of Square Numbers (Medium)](https://leetcode.com/problems/sum-of-square-numbers/)

<p>Given a non-negative integer <code>c</code>, decide whether there're two integers <code>a</code> and <code>b</code> such that <code>a<sup>2</sup> + b<sup>2</sup> = c</code>.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> c = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> 1 * 1 + 2 * 2 = 5
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> c = 3
<strong>Output:</strong> false
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> c = 4
<strong>Output:</strong> true
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 &lt;= c &lt;= 2<sup>31</sup> - 1</code></li>
</ul>



**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Two Pointers](https://leetcode.com/tag/two-pointers/)



## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/sum-of-square-numbers/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while (left <= right){
            long cur = left * left + (long)right * right;
            if (cur == c)
                return true;
            else if (cur < c)
                left++;
            else 
                right--;
        }
        return false;
    }
};
```

