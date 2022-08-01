# [2023. Number of Pairs of Strings With Concatenation Equal to Target (Medium)](https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/)

<p>Given an array of <strong>digit</strong> strings <code>nums</code> and a <strong>digit</strong> string <code>target</code>, return <em>the number of pairs of indices </em><code>(i, j)</code><em> (where </em><code>i != j</code><em>) such that the <strong>concatenation</strong> of </em><code>nums[i] + nums[j]</code><em> equals </em><code>target</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = ["777","7","77","77"], target = "7777"
<strong>Output:</strong> 4
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "777" + "7"
- (1, 0): "7" + "777"
- (2, 3): "77" + "77"
- (3, 2): "77" + "77"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = ["123","4","12","34"], target = "1234"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "123" + "4"
- (2, 3): "12" + "34"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = ["1","1","1"], target = "11"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Valid pairs are:
- (0, 1): "1" + "1"
- (1, 0): "1" + "1"
- (0, 2): "1" + "1"
- (2, 0): "1" + "1"
- (1, 2): "1" + "1"
- (2, 1): "1" + "1"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 100</code></li>
	<li><code>2 &lt;= target.length &lt;= 100</code></li>
	<li><code>nums[i]</code> and <code>target</code> consist of digits.</li>
	<li><code>nums[i]</code> and <code>target</code> do not have leading zeros.</li>
</ul>


**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
// Author: github.com/punkfulw
// Time: O(N^2) 
// Space: O(1) 
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] != target.substr(0, nums[i].size()))
                continue;
            for (int j = 0; j < n; j++)
                if (nums[i] + nums[j] == target && i != j)
                    ans++;
        }
        return ans;
    }
};
```

## Solution 2. prefix suffix

```cpp
// OJ: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/discuss/1499860/Prefix-and-Suffix-Counts
// Time: O(N) 
// Space: O(N) 
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0, tar = target.size();
        int pre[101] = {}, suf[101] = {};
        for (auto s: nums){
            int sz = s.size();
            if (sz >= tar)
                continue;
            bool isPre = s == target.substr(0, sz), isSuf = s == target.substr(tar - sz);
            ans += isPre ? suf[sz] : 0;
            ans += isSuf ? pre[tar - sz] : 0;
            suf[tar - sz] += isSuf;
            pre[sz] += isPre;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/discuss/1499270/C%2B%2B-Frequency-Map
