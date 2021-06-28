# [6. ZigZag Conversion (Medium)](https://leetcode.com/problems/zigzag-conversion/)

<p>The string <code>"PAYPALISHIRING"</code> is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)</p>

<pre>P   A   H   N
A P L S I I G
Y   I   R
</pre>

<p>And then read line by line: <code>"PAHNAPLSIIGYIR"</code></p>

<p>Write the code that will take a string and make this conversion given a number of rows:</p>

<pre>string convert(string s, int numRows);</pre>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows = 3
<strong>Output:</strong> "PAHNAPLSIIGYIR"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "PAYPALISHIRING", numRows =&nbsp;4
<strong>Output:</strong>&nbsp;"PINALSIGYAHRPI"
<strong>Explanation:</strong>

P     I    N
A   L S  I G
Y A   H R
P     I</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 1000</code></li>
  <li><code>s</code> consists of English letters (lower-case and upper-case), <code>','</code> and <code>'.'</code>.</li>
  <li><code>1 &lt;= numRows &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/zigzag-conversion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1)
            return s;
        vector<string> rec(numRows);
        int n = numRows + numRows - 2;
        for (int i = 0; i < s.size(); i++){
            int cur = i % n;
            int side = cur / (n / 2);
            if (side < 1)
                rec[cur] += s[i];
            else
                rec[numRows - 1 - cur % (n/2)] += s[i];
        }
        string ans
        for (auto str: rec)
            ans += str;
        return ans;
    }
};
```
