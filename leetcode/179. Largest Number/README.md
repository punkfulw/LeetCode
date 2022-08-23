# [179. Largest Number (Medium)](https://leetcode.com/problems/largest-number/)

<p>Given a list of non negative integers, arrange them such that they form the largest number.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>[10,2]</code>
<strong>Output:</strong> "<code>210"</code></pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>[3,30,34,5,9]</code>
<strong>Output:</strong> "<code>9534330"</code>
</pre>

<p><strong>Note:</strong> The result may be very large, so you need to return a string instead of an integer.</p>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(NW)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> A;
        for (auto i: nums)
            A.push_back(to_string(i));
        
        sort(A.begin(), A.end(), [](string &a, string &b){
            return a + b > b + a;    
        });
        string ans = "";
        for (auto s: A) ans += s;        
        return ans[0] == '0' ? "0" : ans;
        
    }
};
```

## Solution 2. In-place

```cpp
// OJ: https://leetcode.com/problems/largest-number/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(1)
class Solution {
public:
    string largestNumber(vector<int>& A) {
        sort(A.begin(), A.end(), [](int &a, int &b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);    
        });
        string ans = "";
        for (auto s: A) 
            ans += to_string(s);        
        return ans[0] == '0' ? "0" : ans;
    }
};
```
