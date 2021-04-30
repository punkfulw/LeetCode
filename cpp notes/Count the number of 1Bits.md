<p><b>__builtin_popcount</b> is a gcc macro that count the number of 1 you can have in a binary representation.

<p> make_pair(cnt(arr[i]), arr[i]); </p>


```cpp
// OJ: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    
    static bool compare(const int& a, const int& b){
        int c1 = __builtin_popcount(a);
        int c2 = __builtin_popcount(b);
        if(c1 == c2)
            return a < b;
        return c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(),arr.end(), compare);
        return arr;
    }
};
```


```cpp
// OJ: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    int cnt(int n) {
        int c = 0;
        for (; n; n >>= 1) {
            if (n & 1) ++c;
        }
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        int N = arr.size();
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; ++i) v[i] = make_pair(cnt(arr[i]), arr[i]);
        sort(v.begin(), v.end());
        for (int i = 0; i < N; ++i) arr[i] = v[i].second;
        return arr;
    }
};
```
