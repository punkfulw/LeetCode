
## Find index
```
auto it = find(ans.begin(), ans.end(), cur);
ans[distance(ans.begin(), it)]
```


## Bit Manipulation summary
https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently


## Array on heap
Just a C++ tip... In your code above, you have the line "int *zeroOne = new int[2];", which creates an int array dynamically (on the heap). In C++, it's significantly faster to create that same array on the stack using the syntax "int zeroOne[2];". Additionally, since you're creating the array on the heap, you should be calling "delete[] zeroOne;" after you're done using it in order to clean up the heap-allocated memory. However, if you instead created the array on the stack, you would have the additional advantage of not needing to call "delete" at all :)

## Sort with comparator

692. Top K Frequent Words       
<pre>
Comparator for Priority Queue
if (false)
	b in front of a
else
	a in front of b
</pre>
```cpp
class Solution {
public:
    bool operator()(pair<string, int> a, pair<string, int> b){
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (auto word: words)
            mp[word]++;
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, Solution> pq;
        
        for(auto &p : mp) {
            pq.push(p);
        
        vector<string> ans;
        while(pq.size() && k--){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.first);
        }
        return ans;
    }
};
```

1710. Maximum Units on a Truck

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
1030. Matrix Cells in Distance Order


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


## Sort with lambda
1122. Relative Sort Array

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

1636. Sort Array by Increasing Frequency
```cpp
// OJ: https://leetcode.com/problems/relative-sort-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> cnt;
        for (int i: nums){
            cnt[i]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return cnt[a] == cnt[b] ? a > b : cnt[a] < cnt[b];
        });

        return nums;
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
## Char to string
1002. Find Common Characters

<b>string(1, i + 'a')</b>

```cpp
// OJ: https://leetcode.com/problems/find-common-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> ans {};
        
        for (auto s: A){
            vector<int> cnt1(26, 0);
            for (auto c: s)
                cnt1[c-'a']++;
            for (int i = 0; i < 26; i++)
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        for (int i = 0; i < 26; i++){
            while (cnt[i] > 0){
                ans.push_back(string(1, i + 'a'));
                cnt[i]--;
            }
        }
        return ans;
    }
};
```

## Cartesian tree
654. Maximum Binary Tree

<img alt="" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/Cartesian_tree.svg/240px-Cartesian_tree.svg.png" style="width: 600px; height: 150px;">

```cpp
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};
```
