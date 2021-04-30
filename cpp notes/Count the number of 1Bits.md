<p>__builtin_popcount is a gcc macro that count the number of 1 you can have in a binary representation.
As the Problem description say : 
  "You have to sort the integers in the array in ascending order by the number of 1's in their binary representation 
  and in case of two or more integers have the same number of 1's you have to sort them in ascending order"</p>
<p>lets say I have [5,3,8,10] -> [101, 011, 1000, 1010]</p>
<p>In the compare function:
I compare c1== c2, to check if two number can have the same amount of 1's in their binary representation,
for exemple : 3 and 10 have the same amount, so I will take 10, as 10 is greeter than 3</p>
<p>otherwise:
I just compare c1 < c2, to check which number have the most 1's in their binary representation.</p>


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

