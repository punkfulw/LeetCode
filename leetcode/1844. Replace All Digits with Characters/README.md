# [1844. Replace All Digits with Characters (Easy)](https://leetcode.com/problems/replace-all-digits-with-characters/)

<p>You are given a <b>0-indexed</b> string <code>s</code> that has lowercase English letters in its <b>even</b> indices and digits in its <b>odd</b> indices.</p>

<p>There is a function <code>shift(c, x)</code>, where <code>c</code> is a character and <code>x</code> is a digit, that returns the <code>x<sup>th</sup></code> character after <code>c</code>.</p>

<ul>
  <li>For example, <code>shift('a', 5) = 'f'</code> and <code>shift('x', 0) = 'x'</code>.</li>
</ul>

<p>For every <b>odd</b> index <code>i</code>, you want to replace the digit <code>s[i]</code> with <code>shift(s[i-1], s[i])</code>.</p>

<p>Return <code>s</code> <em>after replacing all digits. It is <b>guaranteed</b> that </em><code>shift(s[i-1], s[i])</code> <em>will never exceed</em> <code>'z'</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "a1c1e1"
<strong>Output:</strong> "abcdef"
<strong>Explanation: </strong>The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a1b2c3d4e"
<strong>Output:</strong> "abbdcfdhe"
<strong>Explanation: </strong>The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('b',2) = 'd'
- s[5] -> shift('c',3) = 'f'
- s[7] -> shift('d',4) = 'h'
</pre>


<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [3,3]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 100</code></li>
  <li><code>s</code> consists only of lowercase English letters and digits.</li>
  <li><code>shift(s[i-1], s[i]) <= 'z'</code> for all <b>odd</b> indices <code>i.</code></li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/replace-all-digits-with-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2){
            s[i] = s[i-1] + s[i] - '0';
        }
        return s;
    }
};
```
