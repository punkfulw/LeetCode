// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++){
            if (arr[i])
                continue;
            arr.pop_back();
            arr.insert(arr.begin() + i, 0);
            i++;
        }
        return;
    }
};
