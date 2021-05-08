# [583. Delete Operation for Two Strings (Medium)](https://leetcode.com/problems/delete-operation-for-two-strings)

<p>Given two words <code>word1</code> and <code>word2</code>, return <em>the minimum number of <b>steps</b>. required to make</em> <code>word1</code> 
  <em> and </em><code>word2</code><em> the same.</em></p>
<p>In one <b>step</b>, you can delete exactly one character in either string.</p>


<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "sea", word2 = "eat"
<strong>Output:</strong> 2
<strong>Explanation: </strong> You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "leetcode", word2 = "etco"
<strong>Output:</strong> 4
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= word1.length, word2.length &lt;= 500</code></li>
  <li><code>word1</code> and <code>word2</code> consist of only lowercase English letters.</li>
</ul>



## Solution 1. Longest Common Subsequence


```cpp
// OJ: https://leetcode.com/problems/delete-operation-for-two-strings
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<vector<int>> A(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i < m+1; i++){         
            for (int j = 1; j < n+1; j++){
                if (word2[i-1] == word1[j-1])
                    A[i][j] = A[i-1][j-1] + 1;
                else
                    A[i][j] = max(A[i-1][j], A[i][j-1]);
                
            }
        }
       /********************************************************** 
       * for (int i = 0; i < m+1; i++){         
       *     for (int j = 0; j < n+1; j++){
       *         cout << A[i][j] << " ";        show DP result 
       *     }
       *     cout << endl;
       * }
       ***********************************************************/
        return  m - A[m][n] + n - A[m][n];
    }
};
```
