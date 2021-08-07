# [647. Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

<p>Given a string <code>s</code>, return <em>the number of <b>palindromic substrings</b> in it.</em></p>

<p>A string is a <b>palindromic</b> when it reads the same backward as forward.</p>

<p>A <b>substrings</b> is a contiguous sequence of characters within the string.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "abc"
<b>Output:</b> 3
<b>Explanation:</b> Three palindromic strings: "a", "b", "c".
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "aaa"
<b>Output:</b> 6
<b>Explanation:</b> Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 1000</code></li>
  <li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Pure Storage](https://leetcode.com/company/pure-storage), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Coursera](https://leetcode.com/company/coursera), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/palindromic-substrings/discuss/105691/JavaC%2B%2B-6-lines-solution-NO-DP
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        
        for (int i = 0; i < n; i++){
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
                ans++;
            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)
                ans++;
        }
        return ans;
    }
};
```
