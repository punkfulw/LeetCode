# [67. Add Binary (Easy)](https://leetcode.com/problems/add-binary/)

<p>Given two binary strings, return their sum (also a binary string).</p>

<p>The input strings are both <strong>non-empty</strong> and contains only characters <code>1</code> or&nbsp;<code>0</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> a = "11", b = "1"
<strong>Output:</strong> "100"</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> a = "1010", b = "1011"
<strong>Output:</strong> "10101"</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Each string consists only of <code>'0'</code> or <code>'1'</code> characters.</li>
	<li><code>1 &lt;= a.length, b.length &lt;= 10^4</code></li>
	<li>Each string is either <code>"0"</code> or doesn't contain any leading zero.</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Add Two Numbers (Medium)](https://leetcode.com/problems/add-two-numbers/)
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Plus One (Easy)](https://leetcode.com/problems/plus-one/)
* [Add to Array-Form of Integer (Easy)](https://leetcode.com/problems/add-to-array-form-of-integer/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/add-binary/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/add-binary/discuss/24475/Short-code-by-c%2B%2B
// Time: O(A+B)
// Space: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string ans;
        int i = a.size()-1, j = b.size()-1;
        while (i >= 0 || j >= 0 || c){
            c += i >= 0 ? (a[i--] - '0') : 0;
            c += j >= 0 ? (b[j--] - '0') : 0;
            ans += char(c % 2 + '0');
            c /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/add-binary/
// Author: github.com/punkfulw
// Time: O(A+B)
// Space: O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int n = a.size(), m = b.size();
        for (int i = 1; i <= max(n, m); i++){
            int x = 0, y = 0;
            if (i <= n)
                x = a[n-i] - '0';
            if (i <= m)
                y = b[m-i] - '0';
            switch(x + y + carry){
                case 0:
                    ans.insert(0, "0");
                    carry = 0;
                    break;
                case 1:
                    ans.insert(0, "1");
                    carry = 0;
                    break;
                case 2:
                    ans.insert(0, "0");
                    carry = 1;
                    break;
                case 3:
                    ans.insert(0, "1");
                    carry = 1;
                    break;
            }
        }
        if (carry)
            ans.insert(0, "1");
        return ans;
    }
};
```
