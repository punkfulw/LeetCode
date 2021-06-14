# [696. Count Binary Substrings (Easy)](https://leetcode.com/problems/count-binary-substrings/)

<p>Give a string <code>s</code>, count the number of non-empty (contiguous) substrings that have the same number of <code>0</code>'s and <code>1</code>'s,
  and all the <code>0</code>'s and all the <code>1</code>'s in these substrings are grouped consecutively. 
</p>
<p>Substrings that occur multiple times are counted the number of times they occur.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "00110011"
<b>Output:</b> 6
<b>Explanation:</b> There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "10101"
<b>Output:</b> 4
<b>Explanation:</b> There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
</pre>
<p></p>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
  <li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-binary-substrings/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < s.size()-1; i++){
            if (s[i] == s[i+1])
                continue;
            else{
                int j = i+1;
                ans++;
                while (s[j] == s[j+1] && j-i <= i-pre){
                    j++;
                    ans++;
                }
                pre = i+1;
            }
        }
        return ans;
    }
};
```


## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/count-binary-substrings/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/count-binary-substrings/discuss/108625/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0, cur = 1;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1])
                cur++;
            else{
                ans += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return ans + min(cur, pre);
    }
};
```
