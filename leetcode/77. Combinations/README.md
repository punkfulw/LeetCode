# [77. Combinations (Medium)](https://leetcode.com/problems/combinations/)

<p>Given two integers <em>n</em> and <em>k</em>, return all possible combinations of <em>k</em> numbers out of 1 ... <em>n</em>.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong>&nbsp;n = 4, k = 2
<strong>Output:</strong>
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Combination Sum (Medium)](https://leetcode.com/problems/combination-sum/)
* [Permutations (Medium)](https://leetcode.com/problems/permutations/)

## Solution 1. generate all pair

```cpp 
// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/punkfulw
// Time: O(K!)
// Space: O(K)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int mask = 1 << n;
        vector<vector<int>> ans;
        
        for (int no = 1; no < mask; no++){
            int i = 1;
            int num = no;
            vector<int> cur;
            while (num){
                if (num & 1)
                    cur.push_back(i);
                num >>= 1;
                i++;
            }
            if (cur.size() == k)
                ans.push_back(cur);
        }
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/combinations/
// Author: github.com/punkfulw
// Time: O(K)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        
        vector<int> index(k);
        iota(index.begin(), index.end(), 1);
        
        while (index[0] < n - k + 2){
            vector<int> cur;
            for (auto i: index)
                cur.push_back(i);
            ans.push_back(cur);
            for (int i = k-1; i >= 0; i--){
                if (i > 0 && index[i] == n - k + i + 1)
                    continue;
                ++index[i++];     
                for (; i < k; i++)
                    index[i] = index[i-1] + 1;
                break;
            }
        }
        return ans;
    }
};
```
