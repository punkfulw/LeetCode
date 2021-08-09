# [1417. Reformat The String (Easy)](https://leetcode.com/problems/reformat-the-string/)

<p>Given alphanumeric string <code>s</code>. (<b>Alphanumeric string</b> is a string consisting of lowercase English letters and digits).</p>

<p>You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. 
  That is, no two adjacent characters have the same type.</p>

<p>Return <em>the reformatted string</em> or return <b>an empty string</b> if it is impossible to reformat the string.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s = "a0b1c2"
<strong>Output:</strong> "0a1b2c"
<strong>Explanation:</strong> No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> ""
<strong>Explanation:</strong> "leetcode" has only characters so we cannot separate them by digits.
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> s = "1229857369"
<strong>Output:</strong> ""
<strong>Explanation:</strong> "1229857369" has only digits so we cannot separate them by characters.
</pre>

<p><strong>Example 4:</strong></p>
<pre>
<strong>Input:</strong> s = "covid2019"
<strong>Output:</strong> "c2o0v1i9d"
</pre>


<p><strong>Example 5:</strong></p>
<pre>
<strong>Input:</strong> s = "ab123"
<strong>Output:</strong> "1a2b3"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 500</code></li>
  <li><code>s</code> consists of only lowercase English letters and/or digits</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/reformat-the-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string reformat(string s) {
        string dig, num;
        for (auto c: s){
            if (isdigit(c))
                dig += c;
            else
                num += c;
        }
        if (abs(int(dig.size() - num.size()))>1)
            return "";
        return reform(dig, num);
    }
    string reform(string lon, string sho){
        if (lon.size() < sho.size())
            swap(lon, sho);
        string ans;
        for (int i = 0; i < lon.size(); i++){
            ans += lon[i];
            if (i >= sho.size())
                continue;
            ans += sho[i];
        }
        return ans;
    }
};
```

