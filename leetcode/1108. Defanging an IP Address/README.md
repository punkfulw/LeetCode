# [1108. Defanging an IP Address (Easy)](https://leetcode.com/problems/defanging-an-ip-address/)

<p>Given a valid (IPv4) IP <code>address</code>, return a defanged version of that IP address.</p>

<p>A <em>defanged&nbsp;IP address</em>&nbsp;replaces every period <code>"."</code> with <code>"[.]"</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> address = "1.1.1.1"
<strong>Output:</strong> "1[.]1[.]1[.]1"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> address = "255.100.50.0"
<strong>Output:</strong> "255[.]100[.]50[.]0"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The given <code>address</code> is a valid IPv4 address.</li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/defanging-an-ip-address/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string defangIPaddr(string address) {
        int ans_size = address.size() + 6;
        string ans (ans_size, ' ');
        int i {};
        for (int num = 0; num < ans_size; num++){
            if (address.at(i) != '.'){
                ans.at(num) = address.at(i);
                i++;
            }else{
                ans.at(num++) = '[';
                ans.at(num++) = '.';
                ans.at(num) = ']';
                i++;
            }
        }
        return ans;
    }
};
```
