# [557. Reverse Words in a String III (Easy)](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

<p>Given a string <code>s</code>, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "Let's take LeetCode contest"
<strong>Output:</strong> "s'teL ekat edoCteeL tsetnoc"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "God Ding"
<strong>Output:</strong> "doG gniD"
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
  <li><code>s</code> contains printable <b>ASCII</b> characters.</li>
  <li><code>s</code> does not contain any leading or trailing spaces.</li>
  <li>There is <b>at least one</b> word in <code>s</code>.</li>
  <li>All the words in <code>s</code> are separated by a single space.</li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/string/)



## Solution 1. 
stack

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string ans;
        
        for (auto c: s){
            if (c != ' ')
                stk.push(c);
            else{
                while (!stk.empty()){
                    char l = stk.top();
                    ans.push_back(l);
                    stk.pop();
                }
                ans.push_back(' ');
            }
        }
        while (!stk.empty()){
                    char l = stk.top();
                    ans.push_back(l);
                    stk.pop();
                }
        
        return ans;
    }
};
```

## Solution 2.
find ' ' and reverse in place

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author: github.com/punkfulw
// Refernce: https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/101906/C%2B%2B-Java-Clean-Code
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (s[i] != ' '){
                int j = i;
                for (; j < n && s[j] != ' '; j++){}
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};


```
