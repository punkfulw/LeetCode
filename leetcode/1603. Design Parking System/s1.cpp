// OJ: https://leetcode.com/problems/design-parking-system/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class ParkingSystem {
    vector<int> values {};
public:
    ParkingSystem(int big, int medium, int small){
        values.push_back(big);values.push_back(medium);values.push_back(small);
    }
    bool addCar(int carType) {
        return values.at(carType-1)-- > 0 ;
    }
};
