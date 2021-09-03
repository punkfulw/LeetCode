# [1544. Make The String Great (Easy)](https://leetcode.com/problems/make-the-string-great/)

<p>Given a string <code>s</code> of lower and upper case English letters.</p>

<p>A good string is a string which doesn't have&nbsp;<strong>two adjacent characters</strong> <code>s[i]</code> and <code>s[i + 1]</code> where:</p>

<ul>
	<li><code>0 &lt;= i &lt;= s.length - 2</code></li>
	<li><code>s[i]</code> is a lower-case letter and <code>s[i + 1]</code> is the same letter but in upper-case&nbsp;or <strong>vice-versa</strong>.</li>
</ul>

<p>To make the string good, you can choose <strong>two adjacent</strong> characters that make the string bad and remove them. You can keep doing this until the string becomes good.</p>

<p>Return <em>the string</em> after making it good. The answer is guaranteed to be unique under the given constraints.</p>

<p><strong>Notice</strong> that an empty string is also good.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leEeetcode"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong> In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abBAcC"
<strong>Output:</strong> ""
<strong>Explanation:</strong> We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --&gt; "aAcC" --&gt; "cC" --&gt; ""
"abBAcC" --&gt; "abBA" --&gt; "aA" --&gt; ""
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "s"
<strong>Output:</strong> "s"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> contains only lower and upper case English letters.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1. 
 
```cpp
// OJ: https://leetcode.com/problems/make-the-string-great/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string makeGood(string s) {
        bool move = true;
        while (move && s.size()){
            move = false;
            for (int i = 0; i < s.size()-1; i++){
                if (s[i] == s[i+1])
                    continue;
                if (toupper(s[i]) == s[i+1] || tolower(s[i]) == s[i+1]){
                    s.erase(i, 2);
                    i -= 2;
                    move = true;
                }
            }
        }
        return s;
    }
};
```

## Solution 2.  two pointer
 
```cpp
// OJ: https://leetcode.com/problems/make-the-string-great/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/make-the-string-great/discuss/780897/C%2B%2B-Brute-Force-%2B-Two-Pointers
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string makeGood(string s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++){
            if (p > 0 && abs(s[i] - s[p - 1]) == 32)
                p--;
            else
                s[p++] = s[i];
        }
        return s.substr(0, p);
    }
};
```
