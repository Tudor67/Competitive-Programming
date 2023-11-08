class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int N = prices.size();
        
        vector<int> v = prices;
        partial_sort(v.begin(), v.begin() + 2, v.end());
        
        int diff = money - (v[0] + v[1]);
        if(diff >= 0){
            return diff;
        }
        
        return money;
    }
};