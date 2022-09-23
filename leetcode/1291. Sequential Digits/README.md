# [1291. Sequential Digits (Medium)](https://leetcode.com/problems/sequential-digits/)

<p>An&nbsp;integer has <em>sequential digits</em> if and only if each digit in the number is one more than the previous digit.</p>

<p>Return a <strong>sorted</strong> list of all the integers&nbsp;in the range <code>[low, high]</code>&nbsp;inclusive that have sequential digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> low = 100, high = 300
<strong>Output:</strong> [123,234]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> low = 1000, high = 13000
<strong>Output:</strong> [1234,2345,3456,4567,5678,6789,12345]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>10 &lt;= low &lt;= high &lt;= 10^9</code></li>
</ul>


**Companies**:  
[Splunk](https://leetcode.com/company/splunk)

**Related Topics**:  
[Enumeration](https://leetcode.com/tag/enumeration/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sequential-digits/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {  
        vector<int> ans;
        string start = to_string(low), end = to_string(high), digit = "123456789";
        int len = start.size(), mx_len = end.size();

        for (int l = len; l <= mx_len; l++){
            for (int i = 0; i < 10 - l; i++){
                string s = digit.substr(i, l);
                int cur = stoi(s);
                if (cur >= low && cur <= high)
                    ans.push_back(cur);
            }
        }
        return ans;    
    }
};
```
