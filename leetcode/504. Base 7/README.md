# [504. Base 7 (Easy)](https://leetcode.com/problems/base-7/)

<p>Given an integer <code>num</code>, return <em>a string of its <strong>base 7</strong> representation</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = 100
<strong>Output:</strong> "202"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = -7
<strong>Output:</strong> "-10"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>7</sup> &lt;= num &lt;= 10<sup>7</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. iterative

```cpp
// OJ: https://leetcode.com/problems/base-7/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    string convertToBase7(int num) {
        string s = "";
        int n = abs(num);
        while (n != 0){
            s.push_back('0' + n % 7);
            n /= 7;
        }
        return num == 0 ? "0" : num < 0 ? "-" + string(s.rbegin(), s.rend()) : string(s.rbegin(), s.rend());
    }
};
```

## Solution 2. recursive

```cpp
// OJ: https://leetcode.com/problems/base-7/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    string convertToBase7(int num) {
        if (num < 0)
            return "-" + convertToBase7(-num);
        if (num < 7)
            return to_string(num);
        return convertToBase7(num / 7) + convertToBase7(num % 7);
    }
};
```
