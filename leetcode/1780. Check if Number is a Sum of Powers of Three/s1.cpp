// OJ: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> arr = {1};
        while (arr.back() < 1e7)
            arr.push_back(arr.back() * 3);
        int limit = arr.size();
        for (int i = 0; i <= limit; i++){
            cout << n << endl;
            while (arr[i] <= n && i < limit)
                i++;
            n -= arr[i-1];
            if (n == 0)
                return true;
            limit = i - 1;
            i = 0;
            cout << n << endl;
        }
        return n == 0;
    }
};
