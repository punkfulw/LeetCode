# [2007. Find Original Array From Doubled Array (Medium)](https://leetcode.com/problems/find-original-array-from-doubled-array/)

<p>An integer array <code>original</code> is transformed into a <strong>doubled</strong> array <code>changed</code> by appending <strong>twice the value</strong> of every element in <code>original</code>, and then randomly <strong>shuffling</strong> the resulting array.</p>

<p>Given an array <code>changed</code>, return <code>original</code><em> if </em><code>changed</code><em> is a <strong>doubled</strong> array. If </em><code>changed</code><em> is not a <strong>doubled</strong> array, return an empty array. The elements in</em> <code>original</code> <em>may be returned in <strong>any</strong> order</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> changed = [1,3,4,2,6,8]
<strong>Output:</strong> [1,3,4]
<strong>Explanation:</strong> One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> changed = [6,3,0,1]
<strong>Output:</strong> []
<strong>Explanation:</strong> changed is not a doubled array.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> changed = [1]
<strong>Output:</strong> []
<strong>Explanation:</strong> changed is not a doubled array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= changed.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= changed[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Array of Doubled Pairs (Medium)](https://leetcode.com/problems/array-of-doubled-pairs/)
* [Recover the Original Array (Hard)](https://leetcode.com/problems/recover-the-original-array/)

## Solution 1. CountSort


```cpp
// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans, cnt(2e5 + 1);
        for (auto &i: changed)
            cnt[i]++;
        if (cnt[0] % 2 || n % 2)
            return ans;
        
        for (int i = 0; i <= 1e5; i++){
            int dou = i * 2, num = i == 0 ? cnt[i] / 2 : cnt[i];
            if (!num)
                continue;
            if (cnt[dou] < num)
                return {};
            cnt[dou] -= num;
            for (int j = 0; j < num; j++)
                ans.push_back(i);
        }
        return ans;
        
    }
};
```

## Solution 2. Frequency Map


```cpp
// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        map<int, int> cnt;
        for (auto &i: changed)
            cnt[i]++;
        if (cnt[0] % 2 || n % 2)
            return ans;
        
        for (auto &p: cnt){
            int cur = p.first, dou = cur * 2, num = cur == 0 ? p.second / 2 : p.second;
            if (!num)
                continue;
            if (cnt.find(dou) == cnt.end() || cnt[dou] < num)
                return {};
            cnt[dou] -= num;
            for (int i = 0; i < num; i++)
                ans.push_back(cur);
        }
        return ans;
        
    }
};
```

