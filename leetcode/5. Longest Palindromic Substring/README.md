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
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0, n = s.size();
        string ans;
        
        for (int i = 0; i < n; i++){
            int l = i, r = i + 1;
            while (l >= 0 && r < n){
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }
            if (r - l - 1 > mx){
                mx = r - l - 1;
                ans = s.substr(l + 1, r - l - 1);
            }
            l = i - 1, r = i + 1;
            while (l >= 0 && r < n){
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }
            if (r - l - 1 > mx){
                mx = r - l - 1;
                ans = s.substr(l + 1, r - l - 1);
            }
        }
        return ans;
        
    }
};
```
