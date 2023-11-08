class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int N = prices.size();
        
        vector<int> v = prices;
        nth_element(v.begin(), v.begin() + 1, v.end());
        
        int diff = money - (v[0] + v[1]);
        if(diff >= 0){
            return diff;
        }
        
        return money;
    }
};