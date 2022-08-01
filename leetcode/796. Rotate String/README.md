# [796. Rotate String (Easy)](https://leetcode.com/problems/rotate-string/)

<p>Given two strings <code>s</code> and <code>goal</code>, return <code>true</code> <em>if and only if</em> <code>s</code> <em>can become</em> <code>goal</code> <em>after some number of <strong>shifts</strong> on</em> <code>s</code>.</p>

<p>A <strong>shift</strong> on <code>s</code> consists of moving the leftmost character of <code>s</code> to the rightmost position.</p>

<ul>
	<li>For example, if <code>s = "abcde"</code>, then it will be <code>"bcdea"</code> after one shift.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "cdeab"
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde", goal = "abced"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 100</code></li>
	<li><code>s</code> and <code>goal</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Zoom](https://leetcode.com/company/zoom), [Apple](https://leetcode.com/company/apple), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [LinkedIn](https://leetcode.com/company/linkedin)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [String Matching](https://leetcode.com/tag/string-matching/)

## Solution 1. Brute force simulation

```cpp
// OJ: https://leetcode.com/problems/rotate-string/
// Author: github.com/punkfulw
// Time: O(N ^ N)
// Space: O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = n;
        while (m--){
            if (s == goal)
                return true;
            s = s.substr(1, n - 1) + s[0];
        }
        return false;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/rotate-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};
```
