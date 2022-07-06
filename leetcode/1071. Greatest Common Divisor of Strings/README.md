# [1071. Greatest Common Divisor of Strings (Easy)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

<p>For two strings <code>s</code> and <code>t</code>, we say "<code>t</code> divides <code>s</code>" if and only if <code>s = t + ... + t</code>&nbsp; (<code>t</code> concatenated with itself 1 or more times)</p>

<p>Given two strings str1 and str2, return the largest string <code>x</code> such that <code>x</code> divides both&nbsp;<code><font face="monospace">str1</font></code>&nbsp;and <code><font face="monospace">str2</font></code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> str1 = "ABCABC", str2 = "ABC"
<strong>Output:</strong> "ABC"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> str1 = "ABABAB", str2 = "ABAB"
<strong>Output:</strong> "AB"
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> str1 = "LEET", str2 = "CODE"
<strong>Output:</strong> ""
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> str1 = "ABCDEF", str2 = "ABC"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length &lt;= 1000</code></li>
	<li><code>1 &lt;= str2.length &lt;= 1000</code></li>
	<li><code>str1</code>&nbsp;and <code>str2</code>&nbsp;consist of&nbsp;English uppercase letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (n < m) swap(str1, str2);
        for (int i = min(n, m); i >= 1; i--){
            if (n % i != 0 || m % i != 0)
                continue;
            string gcd = str1.substr(0, i), s1 = "", s2 = "";
            while (s1.size() < str1.size())
                s1 += gcd;
            while (s2.size() < str2.size())
                s2 += gcd;
            if (s1 == str1 && s2 == str2)
                return gcd;
        }
        return "";
    }
};
```

## Solution 2. GCD

```cpp
// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/greatest-common-divisor-of-strings/discuss/307242/C%2B%2B-3-lines
// Time: O(logN) 
// Space: O(1)
class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        return s1 + s2 == s2 + s1 
            ? s1.substr(0, gcd(s1.size(), s2.size()))
            : "";
    }
};
```
