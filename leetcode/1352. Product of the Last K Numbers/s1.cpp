// OJ: https://leetcode.com/problems/product-of-the-last-k-numbers/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(N)
class ProductOfNumbers {
public:
    vector<int> preprod;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if (num == 0){
            preprod = vector<int> {};
            return;
        }
        if (preprod.empty())
            preprod.push_back(num);
        else
            preprod.push_back(num * preprod.back());
    }
    
    int getProduct(int k) {
        int n = preprod.size();
        if (k > n)
            return 0;
        return n == k ? preprod[n - 1] : preprod[n - 1] / preprod[n - k - 1];
    }
};
