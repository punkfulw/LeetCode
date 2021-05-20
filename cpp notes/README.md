## sort with comparator
## 1710. Maximum Units on a Truck

```cpp
class Solution {
public:
    bool static comparator(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comparator);
        int ans=0; //total units
		
        for(int i=0;i<boxTypes.size();i++){
            int box_count=min(boxTypes[i][0],truckSize);
            ans+=box_count*boxTypes[i][1];
            truckSize-=box_count;
            if(truckSize==0)
                break;
        }
        return ans;
    }
};
```


## 1030. Matrix Cells in Distance Order


```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans {};
        
        auto comp = [r0, c0](vector<int> &a, vector<int> &b)
        {
            return abs(a[0]-r0) + abs(a[1]-c0) < abs(b[0]-r0) + abs(b[1]-c0);
        };
        
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                ans.push_back({i, j});                
            }
        }
        
        sort(ans.begin(), ans.end(), comp);
        
        return ans;
    }
};
```

```cpp
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.push_back({i, j, abs(i - r0) + abs(j - c0)});

        sort(ans.begin(), ans.end(), [](vector<int>& c1, vector<int>& c2) {
            return c1[2] < c2[2];
        });

        for (vector<int>& d: ans) 
            d.pop_back();

        return ans;
    }
};
```
## sort with lambda
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

## Count the number of 1Bits

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

