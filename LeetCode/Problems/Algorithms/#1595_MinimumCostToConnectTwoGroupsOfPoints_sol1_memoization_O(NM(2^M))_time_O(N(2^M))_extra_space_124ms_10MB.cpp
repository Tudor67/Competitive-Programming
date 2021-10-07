class Solution {
private:
    static const int INF = 1e8;
    
    int solve(int bit1, int mask2, vector<vector<int>>& cost, vector<vector<int>>& memo){
        const int N1 = cost.size();
        const int N2 = cost[0].size();
        
        if(bit1 < 0){
            if(__builtin_popcount((unsigned int)mask2) == 0){
                return 0;
            }else{
                return INF;
            }
        }
        
        if(memo[bit1][mask2] != -1){
            return memo[bit1][mask2];
        }
        
        int minCost = INF;
        for(int bit2 = 0; bit2 < N2; ++bit2){
            if((mask2 >> bit2) & 1){
                int cost1 = cost[bit1][bit2] + solve(bit1, mask2 - (1 << bit2), cost, memo);
                int cost2 = cost[bit1][bit2] + solve(bit1 - 1, mask2, cost, memo);
                int cost3 = cost[bit1][bit2] + solve(bit1 - 1, mask2 - (1 << bit2), cost, memo);
                minCost = min({minCost, cost1, cost2, cost3});
            }
        }
        memo[bit1][mask2] = minCost;
        return minCost;
    }
    
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        const int N1 = cost.size();
        const int N2 = cost[0].size();
        const int FULL_MASK1 = (1 << N1) - 1;
        const int FULL_MASK2 = (1 << N2) - 1;
        vector<vector<int>> memo(N1, vector<int>(FULL_MASK2 + 1, -1));
        return solve(N1 - 1, FULL_MASK2, cost, memo);
    }
};