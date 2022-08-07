# [1220. Count Vowels Permutation (Hard)](https://leetcode.com/problems/count-vowels-permutation/)

<p>Given an integer <code>n</code>, your task is to count how many strings of length <code>n</code> can be formed under the following rules:</p>

<ul>
	<li>Each character is a lower case vowel&nbsp;(<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>)</li>
	<li>Each vowel&nbsp;<code>'a'</code> may only be followed by an <code>'e'</code>.</li>
	<li>Each vowel&nbsp;<code>'e'</code> may only be followed by an <code>'a'</code>&nbsp;or an <code>'i'</code>.</li>
	<li>Each vowel&nbsp;<code>'i'</code> <strong>may not</strong> be followed by another <code>'i'</code>.</li>
	<li>Each vowel&nbsp;<code>'o'</code> may only be followed by an <code>'i'</code> or a&nbsp;<code>'u'</code>.</li>
	<li>Each vowel&nbsp;<code>'u'</code> may only be followed by an <code>'a'.</code></li>
</ul>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo <code>10^9 + 7.</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 5
<strong>Explanation:</strong> All possible strings are: "a", "e", "i" , "o" and "u".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
</pre>

<p><strong>Example 3:&nbsp;</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 68</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2 * 10^4</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP bottom up

```cpp
// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/count-vowels-permutation/discuss/398173/C%2B%2B-Bottom-up-Recursive-DPs-O(n)-and-Matrix-Exponentiation-O(logn)
// Time: O(N)
// Space: O(1)
#define ll long long
class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1e9 + 7;
        vector<vector<int>> relations{{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
        vector<ll> vowel(5, 1), copy;
        
        while (--n){
            copy = vowel;
            for (int i = 0; i < 5; i++){
                vowel[i] = 0;
                for (int num: relations[i])
                    vowel[i] += copy[num], vowel[i] %= mod;
            }
        }
        ll ans = 0;
        for (int i: vowel){
            ans += i, ans %= mod;
        }
        return ans;
    }
};
```

## Solution 1. DP top-down

```cpp
// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> dp;
    int n, MOD = 1e9 + 7;
    char vowel[6] = {'a', 'e', 'i', 'o', 'u'};
    
    int dfs(int i, char v){
        int c = v == 'a' ? 0 : v == 'e' ? 1 : v == 'i' ? 2 : v == 'o' ? 3 : 4;
        if (i == n)
            return 1;
        if (dp[i][c])
            return dp[i][c];
        int cnt = 0;
        switch(v){
            case '0':
                for (int j = 0; j < 5; j++)
                    cnt = (cnt + dfs(i + 1, vowel[j])) % MOD;
                break;
            case 'a':
                cnt = (cnt + dfs(i + 1, 'e')) % MOD;
                break;
            case 'e':
                cnt = (cnt + dfs(i + 1, 'a')) % MOD;
                cnt = (cnt + dfs(i + 1, 'i')) % MOD;
                break;
            case 'i':
                for (int j = 0; j < 5; j++)
                    if (j != 2)
                        cnt = (cnt + dfs(i + 1, vowel[j])) % MOD;
                break;
            case 'o':
                cnt = (cnt + dfs(i + 1, 'i')) % MOD;
                cnt = (cnt + dfs(i + 1, 'u')) % MOD;
                break;
            case 'u':
                cnt = (cnt + dfs(i + 1, 'a')) % MOD;
                break;   
        }
        return dp[i][c] = cnt;
    }
    int countVowelPermutation(int n) {
        this->n = n;
        dp.resize(n + 1, vector<int>(5));
        return dfs(0, '0');
    }
};
```
