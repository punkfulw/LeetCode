# [118. Pascal's Triangle (Easy)](https://leetcode.com/problems/pascals-triangle/)

<p>Given an integer <code>numRows</code>, return the first numRows of <b>Pascal's triangle</b>.</p>

<p>In <b>Pascal's triangle</b>, each number is the sum of the two numbers directly above it as shown:</p>

<p><img alt="" src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" style="height:240px; width:260px"><br>
<small>In Pascal's triangle, each number is the sum of the two numbers directly above it.</small></p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 5
<strong>Output:</strong>
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= numRows &lt;= 30</code></li>
</ul>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/pascals-triangle/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> generate(int R) {
        vector<vector<int>> ans;
        for (int i = 1; i <= R; i++){
            ans.push_back(vector<int> (i, 1));
            if (i <= 2) continue;
            for (int j = 1; j < i - 1; j++){
                ans[i - 1][j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }
        return ans;
    }
};

```

