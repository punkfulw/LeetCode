# [5. Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)

<p>Given a string <code>s</code>, return <em>the longest palindromic substring in</em> <code>s</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "babad"
<strong>Output:</strong> "bab"
<strong>Note:</strong> "aba" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "cbbd"
<strong>Output:</strong> "bb"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> "a"
</pre>


<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "ac"
<strong>Output:</strong> "a"
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 1000</code></li>
  <li><code>s</code> consist of only digits and English letters (lower-case and/or upper-case),</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber), [Pure Storage](https://leetcode.com/company/pure-storage), [eBay](https://leetcode.com/company/ebay), [Alibaba](https://leetcode.com/company/alibaba), [LinkedIn](https://leetcode.com/company/linkedin), [Cisco](https://leetcode.com/company/cisco), [NetEase](https://leetcode.com/company/netease), [Oracle](https://leetcode.com/company/oracle), [Roblox](https://leetcode.com/company/roblox)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size(), i = 0;
        int start_index, longest = 0;
        if (s.size() <= 1)
            return s;
        while (i < n){
            int st = i, ed = i;
            while (s[ed] == s[ed+1] && ed < n-1)
                ed++;
            i = ed+1;
            while (st > 0 && ed < n - 1 && s[st-1] == s[ed+1]){
                st--;
                ed++;
            }
            int cur = ed - st + 1;
            if (cur > longest){
                start_index = st;
                longest = cur;
            }
        }
        return s.substr(start_index, longest);
    }
};
```
