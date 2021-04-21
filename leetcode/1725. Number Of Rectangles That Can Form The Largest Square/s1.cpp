// OJ: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max {};
        int ans {};
        int size = rectangles.size();
        vector<int> len (size, 0);
        
        for (int i = 0; i < size; i++){
            len[i] = min(rectangles[i].at(0), rectangles[i].at(1));
            if (len[i] > max)
                max = len[i];
        }
        
        for (int i = 0; i < size; i++){
            if (len[i] == max)
                ans++;
        }
        return ans;
    }
};
