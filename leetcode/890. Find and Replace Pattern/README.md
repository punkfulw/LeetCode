# [890. Find and Replace Pattern (Medium)](https://leetcode.com/problems/find-and-replace-pattern/)

<p>You have a list of&nbsp;<code>words</code> and a <code>pattern</code>, and you want to know which words in <code>words</code> matches the pattern.</p>

<p>A word matches the pattern if there exists a permutation of letters <code>p</code> so that after replacing every letter <code>x</code> in the pattern with <code>p(x)</code>, we get the desired word.</p>

<p>(<em>Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.</em>)</p>

<p>Return a list of the words in <code>words</code>&nbsp;that match the given pattern.&nbsp;</p>

<p>You may return the answer in any order.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>words = <span id="example-input-1-1">["abc","deq","mee","aqq","dkd","ccc"]</span>, pattern = <span id="example-input-1-2">"abb"</span>
<strong>Output: </strong><span id="example-output-1">["mee","aqq"]</span>
<strong><span>Explanation: </span></strong>"mee" matches the pattern because there is a permutation {a -&gt; m, b -&gt; e, ...}. 
"ccc" does not match the pattern because {a -&gt; c, b -&gt; c, ...} is not a permutation,
since a and b map to the same letter.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 50</code></li>
	<li><code>1 &lt;= pattern.length = words[i].length&nbsp;&lt;= 20</code></li>
</ul>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-and-replace-pattern/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-and-replace-pattern/discuss/1221096/Easy-Solutions-w-Explanation-or-Two-Maps-Single-Map-and-Word-Normalization
// Time: O(N*L) , where N is the number of words and L is the length of each word.
// Space: O(N*L)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans {};
        pattern = nomalize(pattern);
        for (auto word: words){
            if (nomalize(word) == pattern)
                ans.push_back(word);
        }
        return ans;
    }
    
    string nomalize(string word){
        unordered_map<char, char> mp;
        char c = 'a';
        
        for (auto ch: word)
            if (!mp.count(ch))
                mp[ch] = c++;
        
        for (auto& ch: word)
            ch = mp[ch];
        return word;
    }
};
```

## Solution 2. 2022

```cpp
// OJ: https://leetcode.com/problems/find-and-replace-pattern/
// Author: github.com/punkfulw
// Time: O(N*L) , where N is the number of words and L is the length of each word.
// Space: O(N*L)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans {};
        pattern = nomalize(pattern);
        for (auto word: words){
            if (nomalize(word) == pattern)
                ans.push_back(word);
        }
        return ans;
    }
    
    string nomalize(string word){
        unordered_map<char, char> mp;
        char c = 'a';
        
        for (auto ch: word)
            if (!mp.count(ch))
                mp[ch] = c++;
        
        for (auto& ch: word)
            ch = mp[ch];
        return word;
    }
};
```
