# [1839. Longest Substring Of All Vowels in Order (Medium)](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/)

<p>A string is considered <b>beautiful</b>. if it satisfies the following conditions:</p>

<ul>
	<li>Each of the 5 English vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>) must appear <b>at least once</b>. in it.</li>
	<li>The letters must be sorted in <b>alphabetical order</b> (i.e. all <code>'a'</code>s before <code>'e'</code>s, all <code>'e'</code>s before <code>'i'</code>s, etc.).</li>
</ul>

<p>For example, strings <code>"aeiou"</code> and <code>"aaaaaaeiiiioou"</code> are considered <b>beautiful</b>,
  but <code>"uaeio"</code>, <code>"aeoiu"</code>, and <code>"aaaeeeooo"</code> are <b>not beautiful</b>.</p>
  
<p>Given a string <code>word</code> consisting of English vowels, 
  return <em>the <b>length of the longest beautiful substring</b> of </em><code>word</code>.<em> If no such substring exists, return</em> <code>0</code>.</p>
  
 <p>A <b>substring</b> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aeiaaio<em>aaaaeiiiiouuu</em>ooaauuaeiu"
<strong>Output:</strong> 13
<strong>Explanation:</strong> The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
</pre>



word consists of characters 'a', 'e', 'i', 'o', and 'u'.

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "aeeeiiiioooauuu<em>aeiou</em>"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest beautiful substring in word is "aeiou" of length 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word = "a"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no beautiful substring, so return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists of characters <code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)  [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans {};
        
        for (int i = 0; i < word.size(); i++){
            if (word[i] == 'a'){
                int j = i;
                int maxs = 0;
                char current = 'a';
                while (j < word.size() && word[j] >= current){ 
                    current = word[j];
                    maxs++;
                    j++;
                }
                
                string s = word.substr(i, j-i);
                if (word[j-1] == 'u' && s.find('e') != string::npos && s.find('i') != string::npos && s.find('o') != string::npos)
                    ans = max(maxs, ans);
                i = j-1;
             }
            
        }
        return ans;  
    }
};
```
