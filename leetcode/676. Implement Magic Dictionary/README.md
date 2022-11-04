# [676. Implement Magic Dictionary (Medium)](https://leetcode.com/problems/implement-magic-dictionary/)

<p>
Implement a magic directory with <code>buildDict</code>, and <code>search</code> methods.
</p>

<p>
For the method <code>buildDict</code>, you'll be given a list of non-repetitive words to build a dictionary.
</p>

<p>
For the method <code>search</code>, you'll be given a word, and judge whether if you modify <b>exactly</b> one character into <b>another</b> character in this word, the modified word is in the dictionary you just built.
</p>

<p><b>Example 1:</b><br>
</p><pre>Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>You may assume that all the inputs are consist of lowercase letters <code>a-z</code>.</li>
<li>For contest purpose, the test data is rather small by now. You could think about highly efficient algorithm after the contest.</li>
<li>Please remember to <b>RESET</b> your class variables declared in class MagicDictionary, as static/class variables are <b>persisted across multiple test cases</b>. Please see <a href="https://leetcode.com/faq/#different-output">here</a> for more details.</li>
</ol>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Trie](https://leetcode.com/tag/trie/)

## Solution 1. Trie

```cpp
// OJ: https://leetcode.com/problems/implement-magic-dictionary/
// Author: github.com/punkfulw
// Time:
//   buildDict: O(N) 
//   search: O(N^W) Where W is the length of words
// Space: O(N)
class MagicDictionary {
public:
    MagicDictionary() {
    }
    unordered_map<int, vector<string>> mp;
    
    void buildDict(vector<string> dictionary) {
        for (auto &s: dictionary){
            int len = s.size();
            mp[len].push_back(s);
        }
    }
    
    bool search(string searchWord) {
        int len = searchWord.size();
        for (auto &s: mp[len]){
            int dif = 0;
            for (int i = 0; i < len; i++)
                if (s[i] != searchWord[i])
                    dif++;
            if (dif == 1)
                return true;
        }
        return false;
    }
};

```
