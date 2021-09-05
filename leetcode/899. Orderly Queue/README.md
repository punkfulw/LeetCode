# [899. Orderly Queue (Hard)](https://leetcode.com/problems/orderly-queue/)

<p>You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..</p>

<p>Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s = "cba", k = 1
<strong>Output:</strong> "acb"
<strong>Explanation:</strong> 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s = "baaca", k = 3
<strong>Output:</strong> "aaabc"
<strong>Explanation:</strong> 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= k &lt;= s.length &lt;= 1000</code></li>
  <li><code>s consist of lowercase English letters.</code></li>
</ul>



**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)


## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        string ans = s;
        for (int i = 1; i < s.size(); i++){
            string cur = s.substr(i) + s.substr(0, i);
            ans = min(ans, cur);
        }
        return ans;
    }
};
```
