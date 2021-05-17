# [1207. Unique Number of Occurrences (Easy)](https://leetcode.com/problems/unique-number-of-occurrences/)

<p>Given an array of integers <code>arr</code>,&nbsp;write a function that returns <code>true</code> if and only if the number of occurrences of each value in the array is unique.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,2,1,1,3]
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [-3,0,1,-3,1,1,1,-3,10,0]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length&nbsp;&lt;= 1000</code></li>
	<li><code>-1000 &lt;= arr[i] &lt;= 1000</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.
count

```cpp
// OJ: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int cnt[2001] = {};
        
        for (int i: arr){
            cnt[i+1000]++;
        }
        int cmp[1001] = {};
            
        for (int i: cnt){
            if(cmp[i] == 0)
                cmp[i] = i;
            else
                return false;
        }
        return true;
    }
};
```

## Solution 2.
hash table

```cpp
// OJ: https://leetcode.com/problems/unique-number-of-occurrences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp{};
        unordered_set<int> s{};
        
        for (int i: arr){
            mp[i]++;
        }
        for (auto p: mp){
            if (s.count(p.second))
                return false;
            s.insert(p.second);
        }
        return true;
    }
};
```
