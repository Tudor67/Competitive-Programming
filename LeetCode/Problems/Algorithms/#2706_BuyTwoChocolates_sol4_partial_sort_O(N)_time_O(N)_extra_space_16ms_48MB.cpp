class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        const int N = prices.size();
        
        vector<int> v = prices;
        for(int i = 0; i < 2; ++i){
            for(int j = i + 1; j < N; ++j){
                if(v[i] > v[j]){
                    swap(v[i], v[j]);
                }
            }
        }
        
        int diff = money - (v[0] + v[1]);
        if(diff >= 0){
            return diff;
        }
        
        return money;
    }
};