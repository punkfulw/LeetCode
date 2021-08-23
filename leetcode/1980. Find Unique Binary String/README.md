# [1980. Find Unique Binary String (Medium)](https://leetcode.com/problems/find-unique-binary-string/)

<p>Given an array of strings <code>nums</code> containing <code>n</code> <strong>unique</strong> binary strings each of length <code>n</code>, return <em>a binary string of length </em><code>n</code><em> that <strong>does not appear</strong> in <code>nums</code>. If there are multiple answers, you may return <strong>any</strong> of them</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = ["01","10"]
<strong>Output:</strong> "11"
<strong>Explanation:</strong> "11" does not appear in nums. "00" would also be correct.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = ["00","01"]
<strong>Output:</strong> "11"
<strong>Explanation:</strong> "11" does not appear in nums. "10" would also be correct.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = ["111","011","001"]
<strong>Output:</strong> "101"
<strong>Explanation:</strong> "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>nums[i].length == n</code></li>
	<li><code>nums[i] </code>is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Similar Questions**:
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Random Pick with Blacklist (Hard)](https://leetcode.com/problems/random-pick-with-blacklist/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-unique-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(2^N)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<int> cnt(pow(2, n));
        vector<int> used;
        iota(cnt.begin(), cnt.end(), 0);
        
        for (int i = 0; i < n; i++){
            int cur = 0;
            for (int k = 0; k < n; k++){
                cur += (nums[i][k]-'0') * pow(2, k);
            }
            used.push_back(cur);
        }
        
        string s;
        for (int i = n - 1 ; i >= 0; i++){
            int x = cnt[i];
            if (!count(used.begin(), used.end(), x)){
                while (x > 0){
                    s += (x % 2) + '0';
                    x /= 2;
                }
                break;
            }
        }
        while (s.size() != n){
            s += '0';
        }
        return s;
    }
};
```

## Solution 2.   Cantor's Diagonalization

```cpp
// OJ: https://leetcode.com/problems/find-unique-binary-string/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/find-unique-binary-string/discuss/1418687/Detailed-Explanation-O(N)-Java-C%2B%2B-Python-short-concise-code-Cantor's-Diagonalization
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++)
            ans += nums[i][i] == '0' ? '1' : '0';
        return ans;
    }
};
```
