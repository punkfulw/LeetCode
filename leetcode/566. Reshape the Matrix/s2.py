# OJ: https://leetcode.com/problems/reshape-the-matrix/
# Author: github.com/punkfulw
# Time: O(N*M)
# Space: O(r*c)
import numpy as np
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        try:
            return np.reshape(mat, (r, c)).tolist()
        except:
            return mat
