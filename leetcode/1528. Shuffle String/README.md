# [1528. Shuffle String (Easy)](https://leetcode.com/problems/shuffle-string/)

<p>Given a string <code>s</code> and an integer array <code>indices</code> of the <b>same length</b>.</p>

<p>The string <code>s</code> will be shuffled such that the character at the <code>ith</code> position moves to <code>indices[i]</code> in the shuffled string.

Return the *shuffled string.*</p>


<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![image](picture or gif url)

<pre><strong>Input:</strong> s = "codeleet", indices = [4,5,6,7,0,2,1,3]
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong> As shown, "codeleet" becomes "leetcode" after shuffling.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abc", indices = [0,1,2]
<strong>Output:</strong> "abc"
<strong>Explanation: </strong> After shuffling, each character remains in its position.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aiohn", indices = [3,1,4,2,0]
<strong>Output:</strong> "nihao"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
<strong>Output:</strong> "arigatou"
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "art", indices = [1,0,2]
<strong>Output:</strong> "rat"
</pre>

s.length == indices.length == n
1 <= n <= 100
s contains only lower-case English letters.
0 <= indices[i] < n
All values of indices are unique (i.e. indices is a permutation of the integers from 0 to n - 1).


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>s.length == indices.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>s</code> contains only lower-case English letters.</li>
  <li><code>0 &lt;= indices[i] &lt;= n</code></li>
  <li>All values of <code>indices</code> are unique (i.e. <code>indices</code> is a permutation of the integers from <code>0</code> to <code>n - 1</code>).</li>
</ul>

**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/shuffle-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        for (int i = 0; i < s.size(); i++){
            ans[(indices.at(i))] = s.at(i); 
        }
        return ans;
    }
};
```
