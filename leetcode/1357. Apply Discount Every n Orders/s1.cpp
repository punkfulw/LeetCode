// OJ: https://leetcode.com/problems/apply-discount-every-n-orders/
// Author: github.com/punkfulw
// Time:
//      Cashier: O(P) where P is the count of all products
//      getBill: O(N) where N is the count of product the customer bought
// Space: O(P)
class Cashier {
public:
    int cnt = 0, dis, n;
    unordered_map<int, int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->dis = discount;
        for (int i = 0; i < products.size(); i++)
            mp[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double bill = 0;
        for (int i = 0; i < product.size(); i++)
            bill += amount[i] * mp[product[i]];
        if (cnt % n == 0)
            bill *= (1 - (double)dis / 100);
        return bill;
    }
};
