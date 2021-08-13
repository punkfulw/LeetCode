# [47. Permutations II (Medium)](https://leetcode.com/problems/permutations-ii/)

<p>Given a collection of numbers, <code>nums</code>,&nbsp;that might contain duplicates, return <em>all possible unique permutations <strong>in any order</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong>
[[1,1,2],
 [1,2,1],
 [2,1,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 8</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Next Permutation (Medium)](https://leetcode.com/problems/next-permutation/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)
* [Number of Squareful Arrays (Hard)](https://leetcode.com/problems/number-of-squareful-arrays/)



## Solution 1.


```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N^2)
class Solution {
    set<vector<int>> st;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        perm(0, n, nums, ans);
        return ans;
    }
    
    void perm(int i, int n, vector<int>& nums, vector<vector<int>>& ans){
        if (i == n)
            return;
        if (!st.count(nums)){
            st.insert(nums);
            ans.push_back(nums);
        }
        for (int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            perm(i+1, n, nums, ans);
            swap(nums[i], nums[j]);
        }
        return;
    }  
};
```



## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
// Time: O(N!)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        perm(0, n, nums, ans);
        return ans;
    }
    
    void perm(int i, int n, vector<int> nums, vector<vector<int>>& ans){
        if (i == n-1){
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++){
            if (j != i && nums[i] == nums[j])
                continue;
            swap(nums[i], nums[j]);
            perm(i+1, n, nums, ans);
        }
        return;
    }  
};
```

## Solution 3.


```cpp
// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Ref: https://youtu.be/nYFd7VHKyWQ
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> digit;
    vector<int> cnt;
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> mp;
        for (int num: nums)
            mp[num]++;
        for (auto p: mp){
            digit.push_back(p.first);
            cnt.push_back(p.second);
        }
        dfs(nums, 0, nums.size());
        return ans;
    }  
    
    void dfs(vector<int>& nums, int start, int n){
        if (start == n){
            ans.push_back(nums);
            return;
        }
        for (int i = 0; i < cnt.size(); i++){
            if (!cnt[i])
                continue;
            cnt[i]--;
            nums[start] = digit[i];
            dfs(nums, start+1, n);
            cnt[i]++;
        }
    }
};
```
