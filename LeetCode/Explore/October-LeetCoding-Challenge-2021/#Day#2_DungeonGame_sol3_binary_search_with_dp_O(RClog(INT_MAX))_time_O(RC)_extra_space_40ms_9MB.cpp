class Solution {
private:
    static const int INF = 1e8;
    
    bool isValid(const vector<vector<int>>& DUNGEON, const int& INITIAL_HEALTH){
        if(DUNGEON[0][0] + INITIAL_HEALTH <= 0){
            return false;
        }
        
        const int ROWS = DUNGEON.size();
        const int COLS = DUNGEON[0].size();
        
        static vector<vector<int>> dp;
        if((int)dp.size() != ROWS || (int)dp[0].size() != COLS){
            dp.clear();
            dp.resize(ROWS, vector<int>(COLS));
        }
        
        for(int row = 0; row < ROWS; ++row){
            fill(dp[row].begin(), dp[row].end(), -INF);
        }
        
        dp[0][0] = DUNGEON[0][0] + INITIAL_HEALTH;
        
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 && col == 0){
                    continue;
                }
                if(row >= 1 && col >= 1 && dp[row - 1][col] >= 1 && dp[row][col - 1] >= 1){
                    dp[row][col] = DUNGEON[row][col] + max(dp[row - 1][col], dp[row][col - 1]);
                }else if(row >= 1 && dp[row - 1][col] >= 1){
                    dp[row][col] = DUNGEON[row][col] + dp[row - 1][col];
                }else if(col >= 1 && dp[row][col - 1] >= 1){
                    dp[row][col] = DUNGEON[row][col] + dp[row][col - 1];
                }
            }
        }
        
        if(dp[ROWS - 1][COLS - 1] <= 0){
            return false;
        }
        
        return true;
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {        
        int l = 1;
        int r = INF;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(dungeon, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};