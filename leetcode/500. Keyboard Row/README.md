# [500. Keyboard Row (Easy)](https://leetcode.com/problems/keyboard-row/)

<p>Given an array of strings <code>words</code>, return<em> the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.</em></p>

<p>In the <b>American keyboard</b>:</p>

<ul>
  <li>the first row consists of the characters <code>"qwertyuiop"</code>,</li>
  <li>the second row consists of the characters <code>"asdfghjkl"</code>, and</li>
  <li>the third row consists of the characters <code>"zxcvbnm"</code>.</li>
</ul>
<img alt="" src="https://assets.leetcode.com/uploads/2018/10/12/keyboard.png" style="width: 600px; height: 150px;">


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> words = ["Hello","Alaska","Dad","Peace"]
<strong>Output:</strong> ["Alaska","Dad"]
</pre>


<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> words = ["omk"]
<strong>Output:</strong> []
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> words = ["adsdf","sfd"]
<strong>Output:</strong> ["adsdf","sfd"]
</pre>

1 <= words.length <= 20
1 <= words[i].length <= 100
words[i] consists of English letters (both lowercase and uppercase). 

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= words.length &lt;= 20</code></li>
  <li><code>1 &lt;= words[i].length &lt;= 100</code></li>
  <li><code>words[i]</code> consists of English letters (both lowercase and uppercase).</li>
</ul>



**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/keyboard-row/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/keyboard-row/discuss/97872/C%2B%2B-solution-with-3-hash-tables
// Time: O(NM)
// Space: O(1)
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<unordered_set<char>> dict = {
            {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T', 'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'},
            {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j', 'J', 'k', 'K', 'l', 'L'},
            {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm', 'M'}};

        vector<string> res;

        for (auto &word : words) {
            vector<bool> d(3, true);

            for (auto &ch : word)
                for (int i = 0; i < 3; ++i)
                    if (d[i] && dict[i].find(ch) == dict[i].end())
                        d[i] = false;

            if (d[0] || d[1] || d[2])
                res.push_back(word);
        }
        return res;
    }
};
```

