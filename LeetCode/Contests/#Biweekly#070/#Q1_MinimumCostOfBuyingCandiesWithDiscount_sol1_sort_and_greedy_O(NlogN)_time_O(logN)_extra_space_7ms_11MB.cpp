class Solution {
public:
    int minimumCost(vector<int>& cost) {
        const int N = cost.size();
        
        sort(cost.rbegin(), cost.rend());
        
        int minTotalCost = 0;
        int i = 0;
        while(i < N){
            if(i + 2 < N){
                minTotalCost += cost[i];
                minTotalCost += cost[i + 1];
                i += 3;
            }else{
                minTotalCost += cost[i];
                i += 1;
            }
        }
        
        return minTotalCost;
    }
};