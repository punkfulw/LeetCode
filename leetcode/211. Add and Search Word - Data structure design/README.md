# [211. Design Add and Search Words Data Structure (Medium)](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

<p>Design a data structure that supports adding new words and finding if a string matches any previously added string.</p>

<p>Implement the <code>WordDictionary</code> class:</p>

<ul>
	<li><code>WordDictionary()</code>&nbsp;Initializes the object.</li>
	<li><code>void addWord(word)</code> Adds <code>word</code> to the data structure, it can be matched later.</li>
	<li><code>bool search(word)</code>&nbsp;Returns <code>true</code> if there is any string in the data structure that matches <code>word</code>&nbsp;or <code>false</code> otherwise. <code>word</code> may contain dots <code>'.'</code> where dots can be matched with any letter.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example:</strong></p>

<pre><strong>Input</strong>
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
<strong>Output</strong>
[null,null,null,null,false,true,true,true]

<strong>Explanation</strong>
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 500</code></li>
	<li><code>word</code> in <code>addWord</code> consists lower-case English letters.</li>
	<li><code>word</code> in <code>search</code> consist of&nbsp; <code>'.'</code> or lower-case English letters.</li>
	<li>At most <code>50000</code>&nbsp;calls will be made to <code>addWord</code>&nbsp;and <code>search</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Oracle](https://leetcode.com/company/oracle), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Design](https://leetcode.com/tag/design/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)
* [Prefix and Suffix Search (Hard)](https://leetcode.com/problems/prefix-and-suffix-search/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author: github.com/punkfulw
// Time:
//      WordDictionary: O(1)
//      addWord: O(W)
//      search: O(26^3) there's at most 3 '.' in a word
// Space: O(NW)
class TrieNode {
public:
    int end;
    TrieNode* child[26];
    
    TrieNode () : end(0){
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};
class WordDictionary {
public:
    TrieNode *root = new TrieNode();
    
    WordDictionary() {
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for (auto c: word){
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->end = 1;
    }
    
    bool check(TrieNode *node, string &word, int idx){
        if (idx == word.size())
            return node->end == 1;
        bool ret = false;
        char c = word[idx];     
        
        if (c == '.'){
            for (int i = 0; i < 26 && !ret; i++){
                if (node->child[i])
                    ret |= check(node->child[i], word, idx + 1);
            }
        }
        else {
            if (node->child[c - 'a'] == nullptr)
                    return false;
                ret |= check(node->child[c - 'a'], word, idx + 1);
        }
            
        return ret;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        return check(node, word, 0);
    }
};
```
