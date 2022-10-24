# [1239. Maximum Length of a Concatenated String with Unique Characters (Medium)](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)

<p>Given an array of strings <code>arr</code>. String <code>s</code> is a concatenation of a sub-sequence of <code>arr</code> which have <strong>unique characters</strong>.</p>

<p>Return <em>the maximum possible length</em> of <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = ["un","iq","ue"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = ["cha","r","act","ers"]
<strong>Output:</strong> 6
<strong>Explanation:</strong> Possible solutions are "chaers" and "acters".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = ["abcdefghijklmnopqrstuvwxyz"]
<strong>Output:</strong> 26
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 16</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 26</code></li>
	<li><code>arr[i]</code> contains only lower case English letters.</li>
</ul>


**Companies**:  
[Tesla](https://leetcode.com/company/tesla), [Microsoft](https://leetcode.com/company/microsoft), [DiDi](https://leetcode.com/company/didi), [American Express](https://leetcode.com/company/american-express)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1. Bitmask

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int n, ans = 0;
    
    void dfs(int idx, long long vis, vector<string> &arr){
        ans = max(ans, __builtin_popcount(vis));
        if (idx == n)
            return;
        for (int i = idx; i < n; ++i){
            long long nxt = 0LL, tmp;
            for (auto &c: arr[i])
                nxt |= (1 << (c - 'a'));

            if ((nxt & vis) == 0){
                tmp = vis | nxt;
                dfs(i + 1, tmp, arr);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        n = arr.size();
        for (int i = n - 1; i >= 0; i--){
            unordered_set<char> set(arr[i].begin(), arr[i].end());
            if (set.size() != arr[i].size())
                arr.erase(arr.begin() + i);
        }
        n = arr.size();
        
        for (int i = 0; i < n; i++){
            long long vis = 0LL;
            for (auto &c: arr[i])
                vis |= (1 << (c - 'a'));
            dfs(i + 1, vis, arr);
        }
        
        return ans;
    }
};
```

## Solution 2. string set

```cpp
// OJ: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/414806/C%2B%2B-DFS-clean-and-concise-code.
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int sol(vector<string> &arr, string s, int idx){
        unordered_set<char> set(s.begin(), s.end());
        if (set.size() != s.size())
            return 0;
        
        int ans = s.size();
        for (int i = idx; i < arr.size(); ++i){
            ans = max(ans, sol(arr, s + arr[i], i + 1));
        }
        return ans;
    }
    
    int maxLength(vector<string>& arr) {
        return sol(arr, "", 0);
    }
};
```
