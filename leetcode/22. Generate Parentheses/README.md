# [22. Generate Parentheses (Medium)](https://leetcode.com/problems/generate-parentheses/)

<p>Given <code>n</code> pairs of parentheses, write a function to <em>generate all combinations of well-formed parentheses</em>.</p>


<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> ["((()))","(()())","(())()","()(())","()()()"]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> ["()"]
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 8</code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Google](https://leetcode.com/company/google), [Uber](https://leetcode.com/company/uber), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
// Time: O(N)
// Space: O(N)
class Solution {
    void dfs(vector<string>& ans, string& str, int left, int right){
        if (left == 0 && right == 0){
            ans.push_back(str);
            return;
        }
        if (left > 0){
            str.push_back('(');
            dfs(ans, str, left-1, right);
            str.pop_back();
        }
        if (left < right){
            str.push_back(')');
            dfs(ans, str, left, right-1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        dfs(ans, str, n, n);
        return ans;
    }
};
```

## Solution 2. DFS 2022.

```cpp
// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_set<string> ans;    
    void dfs(string s, int l, int r, int n, int cnt){
        if (l == n && r == n && cnt == 0){
            ans.insert(s);
            return;
        }
        if (cnt < 0 || l > n || r > n)
            return;
        dfs(s + "(", l + 1, r, n, cnt + 1);
        dfs(s + ")", l, r + 1, n, cnt - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        
        dfs("", 0, 0, n, 0);
        
        return vector<string>(ans.begin(), ans.end());
    }
};
```
