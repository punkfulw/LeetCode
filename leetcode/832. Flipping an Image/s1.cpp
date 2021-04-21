// OJ: https://leetcode.com/problems/flipping-an-image/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int size = image.size();
        
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size/2; j++){
                swap(image[i].at(j), image[i].at(size-j-1));
            }
        }
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (image[i].at(j) == 0)
                    image[i].at(j) = 1;
                else
                    image[i].at(j) = 0;
            }
        }
        return image;
    }
};
