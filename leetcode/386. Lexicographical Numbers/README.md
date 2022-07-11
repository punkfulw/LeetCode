# [386. Lexicographical Numbers (Medium)](https://leetcode.com/problems/lexicographical-numbers/)

<p>
Given an integer <i>n</i>, return 1 - <i>n</i> in lexicographical order.
</p>

<p>
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
</p>

<p>
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
</p>

**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Baidu](https://leetcode.com/company/baidu), [eBay](https://leetcode.com/company/ebay), [Bloomberg](https://leetcode.com/company/bloomberg)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/lexicographical-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int i = 1;
        while (ans.size() < n){
            ans.push_back(i);
            if (i * 10 <= n)
                i *= 10;
            else {
                if (i % 10 == 9 || i + 1 > n){
                    i /= 10;
                    while (i % 10 == 9)
                        i /= 10;
                }
                i++;
            }
        }
        return ans;
    }
};
```
