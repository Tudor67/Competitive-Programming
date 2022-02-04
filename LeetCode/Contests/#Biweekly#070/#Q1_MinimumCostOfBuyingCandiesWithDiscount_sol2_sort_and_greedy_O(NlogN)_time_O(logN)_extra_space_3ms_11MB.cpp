class Solution {
public:
    int minimumCost(vector<int>& cost) {
        const int N = cost.size();
        
        sort(cost.rbegin(), cost.rend());
        
        int minTotalCost = 0;
        for(int i = 0; i < N; ++i){
            if(i % 3 != 2){
                minTotalCost += cost[i];
            }
        }
        
        return minTotalCost;
    }
};