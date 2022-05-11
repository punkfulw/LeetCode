# [1641. Count Sorted Vowel Strings (Medium)](https://leetcode.com/problems/count-sorted-vowel-strings/)

<p>Given an integer <code>n</code>, return <em>the number of strings of length </em><code>n</code><em> that consist only of vowels (</em><code>a</code><em>, </em><code>e</code><em>, </em><code>i</code><em>, </em><code>o</code><em>, </em><code>u</code><em>) and are <strong>lexicographically sorted</strong>.</em></p>

<p>A string <code>s</code> is <strong>lexicographically sorted</strong> if for all valid <code>i</code>, <code>s[i]</code> is the same as or comes before <code>s[i+1]</code> in the alphabet.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> The 5 sorted strings that consist of vowels only are <code>["a","e","i","o","u"].</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 15
<strong>Explanation:</strong> The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 33
<strong>Output:</strong> 66045
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 50</code>&nbsp;</li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> cnt(5, 1);
        for (int i = 2; i <= n; i++){
            int sum = accumulate(cnt.begin(), cnt.end(), 0);
            for (int j = 0; j < 5; j++){
                int temp = cnt[j];
                cnt[j] = sum;
                sum -= temp;
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};
```

## Solution 2.


```cpp
// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int dfs(int n, int prev, int pos)
    {
        if (pos == n)
            return 1;
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            if (i >= prev)
                cnt += dfs(n, i, pos + 1);
        return cnt;
    }
    int countVowelStrings(int n) {
        return dfs(n, -1, 0);
    }
};
```
