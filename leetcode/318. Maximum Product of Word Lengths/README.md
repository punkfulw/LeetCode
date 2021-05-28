# [318. Maximum Product of Word Lengths (Medium)](https://leetcode.com/problems/maximum-product-of-word-lengths/)

<p>Given a string array <code>words</code>, return <em>the maximum value of </em><code>length(word[i]) * length(word[j])</code><em> where the two words do not share common letters</em>. 
  If no such two words exist, return <code>0</code>.</p>
  
<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> words = ["abcw","baz","foo","bar","xtfn","abcdef"]
<strong>Output:</strong> 16
<strong>Explanation: </strong> The two words can be "abcw", "xtfn".
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> words = ["a","ab","abc","d","cd","bcd","abcd"]
<strong>Output:</strong> 4
<strong>Explanation: </strong> The two words can be "ab", "cd".
</pre>

<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> words = ["a","aa","aaa","aaaa"]
<strong>Output:</strong> 0
<strong>Explanation: </strong> o such pair of words.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 &lt;= words.length &lt;= 1000</code></li>
  <li><code>1 &lt;= words[i].length &lt;= 1000</code></li>
  <li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>



**Related Topics**:  
[Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. bitset


```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100
// Time: O(n*(N+n)), where n is the length of words and N is the average length of words
// Space: O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<bitset<26>> map(n);
        int ans = 0;
        
        
        for (int i = 0; i < n; i++){
            for (auto& c: words[i])
                map[i][c - 'a'] = 1;
            for (int j = 0; j < i; j++){
                if (!checkCommon(map[i], map[j])){
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
    
    bool checkCommon(bitset<26>& a, bitset<26>& b){
        for (int i = 0; i < 26; i++){
            if (a[i] && b[i])
                return true;
        }
        return false;
    }
};
```

## Solution 2. bit mask

```cpp
// OJ: https://leetcode.com/problems/maximum-product-of-word-lengths/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C%2B%2B-using-Bitset-and-Bit-masking-or-Beats-100
// Time: O(n*(N+n)), where n is the length of words and N is the average length of words
// Space: O(n)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> arr(n);
        int ans = 0;
        
        for (int i = 0; i < n; i++){
            for (auto& c: words[i])
                arr[i] |= 1<<(c-'a');
            for (int j = 0; j < i; j++){
                if (!(arr[i] & arr[j])){
                    ans = max(ans, int(words[i].size() * words[j].size()));                    
                }
            }
        }
        return ans;
    }
};


```
