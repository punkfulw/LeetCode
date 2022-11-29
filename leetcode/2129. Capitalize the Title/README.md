# [2129. Capitalize the Title (Easy)](https://leetcode.com/problems/capitalize-the-title/)

<p>You are given a string <code>title</code> consisting of one or more words separated by a single space, where each word consists of English letters. <strong>Capitalize</strong> the string by changing the capitalization of each word such that:</p>

<ul>
	<li>If the length of the word is <code>1</code> or <code>2</code> letters, change all letters to lowercase.</li>
	<li>Otherwise, change the first letter to uppercase and the remaining letters to lowercase.</li>
</ul>

<p>Return <em>the <strong>capitalized</strong> </em><code>title</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> title = "capiTalIze tHe titLe"
<strong>Output:</strong> "Capitalize The Title"
<strong>Explanation:</strong>
Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> title = "First leTTeR of EACH Word"
<strong>Output:</strong> "First Letter of Each Word"
<strong>Explanation:</strong>
The word "of" has length 2, so it is all lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> title = "i lOve leetcode"
<strong>Output:</strong> "i Love Leetcode"
<strong>Explanation:</strong>
The word "i" has length 1, so it is lowercase.
The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= title.length &lt;= 100</code></li>
	<li><code>title</code> consists of words separated by a single space without any leading or trailing spaces.</li>
	<li>Each word consists of uppercase and lowercase English letters and is <strong>non-empty</strong>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Detect Capital (Easy)](https://leetcode.com/problems/detect-capital/)
* [To Lower Case (Easy)](https://leetcode.com/problems/to-lower-case/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/capitalize-the-title/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss;
        string s, ans;
        ss << title;
        
        while (ss >> s){
            if (s.size() <= 2){
                for (auto &c: s)
                    c = tolower(c);
            }
            else {
                s[0] = toupper(s[0]);
                for (int i = 1; i < s.size(); ++i)
                    s[i] = tolower(s[i]);
            }
            ans += s + " ";
        }
        ans.pop_back();
        return ans;
    }
};
```
