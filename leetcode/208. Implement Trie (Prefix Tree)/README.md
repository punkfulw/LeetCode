# [208. Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)

<p>A <b>trie</b> (pronounced as "try") or <b>prefix tree</b> is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
  There are various applications of this data structure, such as autocomplete and spellchecker.</p>

<p>Implement the Trie class:</p>

<ul>
	<li><code>Trie()</code> Initializes the trie object.</li>
	<li><code>void insert(String word)</code> Inserts the string <code>word</code> into the trie.</li>
	<li><code>boolean search(String word)</code> Returns <code>true</code> if the string <code>word</code> is in the trie (i.e., was inserted before), and <code>false</code> otherwise.</li>
  <li><code>boolean startsWith(String prefix)</code> Returns <code>true</code> if there is a previously inserted string <code>word</code> that has the prefix <code>prefix</code>, and <code>false</code> otherwise.</li>
</ul>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> 
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
<strong>Output:</strong> 
[null, null, true, false, true, null, true]
<strong>Explanation:</strong> 
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
</pre>

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= word.length, prefix.length &lt;= 2000</code></li>
  <li><code>word</code> and <code>prefix</code> consist only of lowercase English letters.</li>
  <li>At most <code>3 * 10<sup>4</sup></code> calls in total will be made to <code>insert</code>, <code>search</code>, and <code>startsWith</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-trie-prefix-tree/
// Author: github.com/punkfulw
// Time: O(W) for word length in insert/search/startsWith
// Space:
//   insert: O(W)
//   search/startsWith: O(1)
class Trie {
    struct TrieNode{
        bool endword = false;
        TrieNode* child[26] = {};
        
    } root; 
public:
    void insert(string word) {
        auto p = &root;
        for (auto c: word){
            if (p->child[c - 'a'] == NULL)
                p->child[c - 'a'] = new TrieNode;
            p = p->child[c - 'a'];
        }
        p->endword = true;
    }
    bool search(string word) {
        auto p = &root;
        for (auto c: word){
            if (p->child[c - 'a'] == NULL)
                return false;
            p = p->child[c - 'a'];
        }
        return p->endword;
    }
    bool startsWith(string prefix) {
        auto p = &root;
        for (auto c: prefix){
            if (p->child[c - 'a'] == NULL)
                return false;
            p = p->child[c - 'a'];
        }
        return true;
    }
};
```
