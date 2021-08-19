# [91. Decode Ways (Medium)](https://leetcode.com/problems/decode-ways/)

<p>A message containing letters from <code>A-Z</code> is being encoded to numbers using the following mapping:</p>

<pre>'A' -&gt; 1
'B' -&gt; 2
...
'Z' -&gt; 26
</pre>

<p>Given a <strong>non-empty</strong> string containing only digits, determine the total number of ways to decode it.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "12"
<strong>Output:</strong> 2
<strong>Explanation:</strong>&nbsp;It could be decoded as "AB" (1 2) or "L" (12).
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "226"
<strong>Output:</strong> 3
<strong>Explanation:</strong>&nbsp;It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Salesforce](https://leetcode.com/company/salesforce), [Uber](https://leetcode.com/company/uber), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Decode Ways II (Hard)](https://leetcode.com/problems/decode-ways-ii/)

## Solution 1. DP


```cpp
// OJ: https://leetcode.com/problems/decode-ways
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int n = s.size(), pre = 1, ppre = 1;
        for (int i = n-2; i >= 0; i--){
            if (s[i]-'0' > 2 && s[i+1]-'0' == 0 || (s[i]-'0' == 0 && s[i+1]-'0' == 0))
                return 0;
            if (s[i]-'0' > 2 || (s[i+1]-'0' > 6 && s[i]-'0' == 2) || s[i+1]-'0' == 0 || s[i]-'0' == 0 || s[i+2]-'0' == 0)
                ppre = pre;
            else{
                int temp = pre + ppre;
                ppre = pre;
                pre = temp;
            }
                
        }
        return pre;
    }
};
```
