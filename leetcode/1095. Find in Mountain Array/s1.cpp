// OJ: https://leetcode.com/problems/find-in-mountain-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int bs(int l, int r, int target, MountainArray &nums){
        while (l <= r){
            int mid = (r - l) / 2 + l, x = nums.get(mid);
            if (x == target)
                return mid;
            else if (x > target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
    
    int bs2(int l, int r, int target, MountainArray &nums){
        while (l <= r){
            int mid = (r - l) / 2 + l, x = nums.get(mid);
            if (x == target)
                return mid;
            else if (x < target)
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &nums) {
        int n = nums.length(), l = 1, r = n - 1, peak;
        
        while (l <= r){
            int mid = (r - l) / 2 + l;   
            int a = nums.get(mid - 1), b = nums.get(mid), c = nums.get(mid + 1);

            if (a < b && b > c){
                peak = mid;
                break;
            }
            if (a < b)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        
        int left = bs(0, peak, target, nums);
        if (left != -1)
            return left;
        
        int right = bs2(peak, n - 1, target, nums);
        return right;
    }
};
