# [434. Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/)

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any **non-printable** characters.

**Example:**

```
Input: "Hello, my name is John"
Output: 5
```


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-segments-in-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N) 
class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        int ans = 0;
        while (ss >> s){
            ans++;
        }
        return ans;
    }
};
```
