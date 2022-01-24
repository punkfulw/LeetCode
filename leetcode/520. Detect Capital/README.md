# [520. Detect Capital (Easy)](https://leetcode.com/problems/detect-capital/)

<p>We define the usage of capitals in a word to be right when one of the following cases holds:</p>

<ul>
	<li>All letters in this word are capitals, like <code>"USA"</code>.</li>
	<li>All letters in this word are not capitals, like <code>"leetcode"</code>.</li>
	<li>Only the first letter in this word is capital, like <code>"Google"</code>.</li>
</ul>

<p>Given a string <code>word</code>, return <code>true</code> if the usage of capitals in it is right.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> word = "USA"
<strong>Output:</strong> true
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> word = "FlaG"
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists of lowercase and uppercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Capitalize the Title (Easy)](https://leetcode.com/problems/capitalize-the-title/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/detect-capital/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        int type = isupper(word[n - 1]) ? 0 : 1;
        for (int i = n - 2; i >= 1; i--)
        {
            int curT = isupper(word[i]) ? 0 : 1;
            if (type != curT)
                return false;
        }
        if (type == 0)
            return isupper(word[0]);
        return true;
    }
};

```

