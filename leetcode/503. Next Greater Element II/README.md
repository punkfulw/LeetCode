# [503. Next Greater Element II (Medium)](https://leetcode.com/problems/next-greater-element-ii/)

<p>
Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [1,2,1]
<b>Output:</b> [2,-1,2]
<b>Explanation:</b> The first 1's next greater number is 2; <br>The number 2 can't find next greater number; <br>The second 1's next greater number needs to search circularly, which is also 2.
</pre>
<p></p>

<p><b>Note:</b>
The length of given array won't exceed 10000.
</p>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

**Similar Questions**:
* [Next Greater Element I (Easy)](https://leetcode.com/problems/next-greater-element-i/)
* [Next Greater Element III (Medium)](https://leetcode.com/problems/next-greater-element-iii/)

## Solution 1. brute force

```cpp
// OJ: https://leetcode.com/problems/next-greater-element-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MIN);
        for (int i = 0; i < n; i++){
            for (int j = 1; j < n; j++)
                if (nums[(i + j) % n] > nums[i]){
                    ans[i] = nums[(i + j) % n];
                    break;
                }
            if (ans[i] == INT_MIN)
                ans[i] = -1;
        }
        return ans;
    }
};
```

## Solution 2. stack

```cpp
// OJ: https://leetcode.com/problems/next-greater-element-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 2 * n - 1; i >= 0; i--){
            if (!st.empty()){
                while (!st.empty() && st.top() <= nums[i % n])
                    st.pop();
                ans[i % n] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
```
