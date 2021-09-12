# [1758. Minimum Changes To Make Alternating Binary String (Easy)](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)

<p>You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.</p>

<p>The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.</p>

<p>Return the minimum number of operations needed to make s alternating.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s = "0100"
<strong>Output:</strong> 1
<strong>Explanation:</strong> If you change the last character to '1', s will be "0101", which is alternating.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s = "10"
<strong>Output:</strong> 0
<strong>Explanation:</strong> s is already alternating.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> s = "1111"
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
  <li><code>s[i] is either '0' or '1'</code>.</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(string s) {
        int d1 = 0, d2 = 0;
        for (int i = 0; i < s.size(); i++){
            if ((i % 2 && s[i] != '1') ||  (i % 2 == 0 && s[i] != '0'))
                d1++;
            if ((i % 2 == 0 && s[i] != '1') ||  (i % 2 && s[i] != '0'))
                d2++;
        }
        return min(d1, d2);
    }
};
```


```python
// OJ: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution:
    def minOperations(self, s: str) -> int:
        d1 = d2 = 0
        for i in range(len(s)):
            if i % 2:
                if s[i]=='0': d1 += 1
                else: d2 += 1
            else:
                if s[i]=='1': d1 += 1
                else: d2 += 1
        return min(d1, d2)
```

