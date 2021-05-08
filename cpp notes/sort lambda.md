## 1122. Relative Sort Array

```cpp
// OJ: https://leetcode.com/problems/relative-sort-array/
// Author: github.com/lzl124631x
// Time: O(AlogA)
// Space: O(B)
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i) m[B[i]] = i;
        sort(begin(A), end(A), [&](int a, int b) {
            if (m.count(a) && m.count(b)) return m[a] < m[b];
            if (m.count(a) == 0 && m.count(b) == 0) return a < b;
            return m.count(a) > 0;
        });
        return A;
    }
};
```
