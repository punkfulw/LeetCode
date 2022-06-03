# [1864. Minimum Number of Swaps to Make the Binary String Alternating (Medium)](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/)

<p>Given a binary string <code>s</code>, return <em>the <strong>minimum</strong> number of character swaps to make it <strong>alternating</strong>, or </em><code>-1</code><em> if it is impossible.</em></p>

<p>The string is called <strong>alternating</strong> if no two adjacent characters are equal. For example, the strings <code>"010"</code> and <code>"1010"</code> are alternating, while the string <code>"0100"</code> is not.</p>

<p>Any two characters may be swapped, even if they are&nbsp;<strong>not adjacent</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "111000"
<strong>Output:</strong> 1
<strong>Explanation:</strong> Swap positions 1 and 4: "1<u>1</u>10<u>0</u>0" -&gt; "1<u>0</u>10<u>1</u>0"
The string is now alternating.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "010"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The string is already alternating, no swaps are needed.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1110"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Companies**:  
[Société Générale](https://leetcode.com/company/societe-generale)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), ans = 0, cnt1[2] = {0, 0}, cnt2[2] = {0, 0};
        string s1 (n, '0'), s2(n, '1');
        for (int i = 0; i < n; i++){
            s1[i] = i % 2 ? '1' : '0';
            s2[i] = i % 2 ? '0' : '1';
        }
        
        for (int i = 0; i < n; i++){
            if (s1[i] != s[i])
                if (s1[i] == '1') cnt1[0]++;
                else cnt1[1]++;
            else 
                if (s2[i] == '1') cnt2[0]++;
                else cnt2[1]++;
        }
        
        if (cnt1[0] != cnt1[1] && cnt2[0] != cnt2[1])
            ans = -1;
        else if (cnt1[0] == cnt1[1] && cnt2[0] == cnt2[1])
            ans = min(cnt1[0], cnt2[0]);
        else
            ans = cnt1[0] != cnt1[1] ? cnt2[0] : cnt1[0];
        return ans;
    }
};
```
