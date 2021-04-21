# [832. Flipping an Image (Easy)](https://leetcode.com/problems/flipping-an-image/)

Given a binary matrix `A`, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping `[1, 1, 0]` horizontally results in `[0, 1, 1]`.

To invert an image means that each `0` is replaced by `1`, and each `1` is replaced by `0`. For example, inverting `[0, 1, 1]` results in `[1, 0, 0]`.

**Example 1:**

**Input:** \[\[1,1,0\],\[1,0,1\],\[0,0,0\]\]  
**Output:** \[\[1,0,0\],\[0,1,0\],\[1,1,1\]\]  
**Explanation:** First reverse each row: \[\[0,1,1\],\[1,0,1\],\[0,0,0\]\].  
Then, invert the image: \[\[1,0,0\],\[0,1,0\],\[1,1,1\]\]

**Example 2:**

**Input:** \[\[1,1,0,0\],\[1,0,0,1\],\[0,1,1,1\],\[1,0,1,0\]\]  
**Output:** \[\[1,1,0,0\],\[0,1,1,0\],\[0,0,0,1\],\[1,0,1,0\]\]  
**Explanation:** First reverse each row: \[\[0,0,1,1\],\[1,0,0,1\],\[1,1,1,0\],\[0,1,0,1\]\].  
Then invert the image: \[\[1,1,0,0\],\[0,1,1,0\],\[0,0,0,1\],\[1,0,1,0\]\]

**Notes:**

*   `1 <= A.length = A[0].length <= 20`
*   `0 <= A[i][j] <= 1`

## Solution 1.

```cpp
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
```
