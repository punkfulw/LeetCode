# [884. Uncommon Words from Two Sentences (Easy)](https://leetcode.com/problems/uncommon-words-from-two-sentences/)

<p>A <b>sentence</b> is a string of single-space separated words where each word consists only of lowercase letters.</p>

<p>A word is <b>uncommon</b> if it appears exactly once in one of the sentences, and <b>does not appear</b> in the other sentence.</p>

<p>Given two <b>sentences</b> <code>s1</code> and <code>s2</code>, return<em> a list of all the <b>uncommon words</b></em>. You may return the answer in <b>any order</b>.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s1 = "this apple is sweet", s2 = "this apple is sour"
<strong>Output:</strong> ["sweet","sour"]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s1 = "apple apple", s2 = "banana"
<strong>Output:</strong> ["banana"]
</pre>

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s1.length, s2.length &lt;= 200</code></li>
  <li><code>s1</code> and <code>s2</code> consist of lowercase English letters and spaces.</code></li>
  <li><code>s1</code> and <code>s2</code> do not have leading or trailing spaces.</li>
  <li>All the words in <code>s1</code> and <code>s2</code> are separated by a single space.</li>
</ul>



**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)


## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/uncommon-words-from-two-sentences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> s;
        unordered_map<string, int> mp;
        stringstream ss1(s1), ss2(s2);
        string word;
        
        while (ss1 >> word)
            mp[word]++;
        while (ss2 >> word)
             mp[word]++;
        for (auto it: mp){
            if (it.second == 1)
                s.push_back(it.first);
        }

        return s;
    }
};
```
