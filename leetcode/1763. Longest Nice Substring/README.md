# [1763. Longest Nice Substring (Easy)](https://leetcode.com/problems/longest-nice-substring/)

<p>A string <code>s</code> is <strong>nice</strong> if, for every letter of the alphabet that <code>s</code> contains, it appears <strong>both</strong> in uppercase and lowercase. For example, <code>"abABB"</code> is nice because <code>'A'</code> and <code>'a'</code> appear, and <code>'B'</code> and <code>'b'</code> appear. However, <code>"abA"</code> is not because <code>'b'</code> appears, but <code>'B'</code> does not.</p>

<p>Given a string <code>s</code>, return <em>the longest <strong>substring</strong> of <code>s</code> that is <strong>nice</strong>. If there are multiple, return the substring of the <strong>earliest</strong> occurrence. If there are none, return an empty string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "YazaAay"
<strong>Output:</strong> "aAa"
<strong>Explanation: </strong>"aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "Bb"
<strong>Output:</strong> "Bb"
<strong>Explanation:</strong> "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "c"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no nice substrings.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "dDzeE"
<strong>Output:</strong> "dD"
<strong>Explanation: </strong>Both "dD" and "eE" are the longest nice substrings.
As there are multiple longest nice substrings, return "dD" since it occurs earlier.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of uppercase and lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/longest-nice-substring/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";
        for (int i = 0; i < n - 1; i++){
            int cnt[26][2] = {};
            for (int j = i; j < n; j++){
                cnt[tolower(s[j]) - 'a'][(bool)islower(s[j])] = 1;
                int k = 0;
                for (; k < 26; k++)
                    if (cnt[k][0] + cnt[k][1] == 1)
                        break;
                if (k == 26 && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }  
        }
        return ans;
    }
};

```
