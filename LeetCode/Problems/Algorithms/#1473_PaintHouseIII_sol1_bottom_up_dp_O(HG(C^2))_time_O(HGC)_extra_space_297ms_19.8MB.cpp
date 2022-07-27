class Solution {
private:
    int getFirstColor(int initialColor){
        if(initialColor == 0){
            return 1;
        }
        return initialColor;
    }
    
    int getLastColor(int initialColor, const int& MAX_COLOR){
        if(initialColor == 0){
            return MAX_COLOR;
        }
        return initialColor;
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const int HOUSES = m;
        const int TARGET_GROUPS = target;
        const int MAX_COLOR = n;
        const int INF = 1e9;
        
        // dp[i][g][c]: min cost to paint houses[0 .. i] with g continuous groups of the same color
        //              such that houses[i] is painted with color c
        vector<vector<vector<int>>> dp(HOUSES, vector<vector<int>>(TARGET_GROUPS + 2, vector<int>(MAX_COLOR + 1, INF)));
        
        int firstColor = getFirstColor(houses[0]);
        int lastColor = getLastColor(houses[0], MAX_COLOR);
        for(int color = firstColor; color <= lastColor; ++color){
            int colorCost = (houses[0] == 0 ? cost[0][color - 1] : 0);
            dp[0][1][color] = colorCost;
        }
        
        for(int i = 0; i + 1 < HOUSES; ++i){
            for(int groups = 1; groups <= min(i + 1, TARGET_GROUPS); ++groups){
                int firstColor = getFirstColor(houses[i]);
                int lastColor = getLastColor(houses[i], MAX_COLOR);
                for(int color = firstColor; color <= lastColor; ++color){
                    int firstNextColor = getFirstColor(houses[i + 1]);
                    int lastNextColor = getLastColor(houses[i + 1], MAX_COLOR);
                    for(int nextColor = firstNextColor; nextColor <= lastNextColor; ++nextColor){
                        int nextGroups = (color == nextColor ? groups : groups + 1);
                        int nextColorCost = (houses[i + 1] == 0 ? cost[i + 1][nextColor - 1] : 0);
                        dp[i + 1][nextGroups][nextColor] = min(dp[i + 1][nextGroups][nextColor],
                                                               dp[i][groups][color] + nextColorCost);
                    }
                }
            }
        }
        
        int res = *min_element(dp[HOUSES - 1][TARGET_GROUPS].begin(), dp[HOUSES - 1][TARGET_GROUPS].end());
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};