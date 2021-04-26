// OJ: https://leetcode.com/problems/rotate-image/
// Author: github.com/punkfulw
// Time: O(M) Where M is the size of the matrix
// Space: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = (int)matrix.size();
        
        for (int i = 0; i < size; i++){
            int j = i;
            while (j < size){
                swap(matrix[i][j], matrix[j][i]);
                j++;
            }
        }        
        for (int i = 0; i < size; i++){
            int j = 0;
            while (j < size/2){
                swap(matrix[i][j], matrix[i][size-j-1]);
                j++;
            }
        }
    }
};
