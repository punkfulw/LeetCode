// OJ: https://leetcode.com/problems/decode-xored-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int size = encoded.size();
        vector<int> arr (size+1);
        arr[0] = first;
        for (int i = 0; i < size; i++){
            int ans = (encoded[i] ^ arr[i]);
            arr[i+1] = ans;
        }
        return arr;
    }
};
