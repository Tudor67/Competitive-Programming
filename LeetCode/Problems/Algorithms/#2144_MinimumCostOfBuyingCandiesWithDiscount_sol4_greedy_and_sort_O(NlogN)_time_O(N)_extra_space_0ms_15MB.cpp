class Solution {
public:
    int minimumCost(vector<int>& costs) {
        const int N = costs.size();

        vector<int> sortedCosts = costs;
        sort(sortedCosts.begin(), sortedCosts.end());

        int minCost = 0;
        for(int i = N - 1; i >= 0; i -= 3){
            minCost += sortedCosts[i];
            if(i - 1 >= 0){
                minCost += sortedCosts[i - 1];
            }
        }

        return minCost;
    }
};