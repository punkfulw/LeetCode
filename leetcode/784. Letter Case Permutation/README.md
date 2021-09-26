# [784. Letter Case Permutation (Easy)](https://leetcode.com/problems/letter-case-permutation/)


<p>Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.</p>

<p>Return a list of all possible strings we could create. You can return the output in any order.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> s = "a1b2"
<strong>Output:</strong> ["a1b2","a1B2","A1b2","A1B2"]
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> s = "3z4"
<strong>Output:</strong> ["3z4","3Z4"]
</pre>


<p><strong>Example 3:</strong></p>
<pre>
<strong>Input:</strong> s = "12345"
<strong>Output:</strong> ["12345"]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>s will be a string with length between 1 and 12.</code></li>
  <li><code>s will consist only of letters or digits.</code></li>
</ul>



**Related Topics**:  
[String](https://leetcode.com/tag/array/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. backTracking

```cpp
// OJ: https://leetcode.com/problems/letter-case-permutation/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    vector<string> ans;
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        perm(s, 0, n);
        return ans;
    }
    
    void perm(string cur, int start, int n){
        ans.push_back(cur);
        if (start == n)
            return;
        for (int i = start; i < n; i++){
            if (isalpha(cur[i])){
                cur[i] ^= 32;
                perm(cur, i+1, n);
                cur[i] ^= 32;
            }
        }
    }
};
```
