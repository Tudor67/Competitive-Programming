class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int N = costs.size();

        vector<int> sortedCosts = costs;
        sort(sortedCosts.begin(), sortedCosts.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(sortedCosts[i] <= coins){
                coins -= sortedCosts[i];
                res += 1;
            }
        }
        
        return res;
    }
};