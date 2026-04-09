class Solution {
private:
    const int INF = 1e9;

    int f(int k, int row, int col, vector<vector<int>>& coins, vector<vector<vector<int>>>& memo){
        if(k < 0 || row < 0 || col < 0){
            return -INF;
        }

        if(row == 0 && col == 0){
            if(k == 0){
                return coins[row][col];
            }
            return max(0, coins[row][col]);
        }

        if(memo[k][row][col] != -INF){
            return memo[k][row][col];
        }

        memo[k][row][col] = max({coins[row][col] + f(k, row - 1, col, coins, memo),
                                 coins[row][col] + f(k, row, col - 1, coins, memo),
                                 max(0, coins[row][col]) + f(k - 1, row - 1, col, coins, memo),
                                 max(0, coins[row][col]) + f(k - 1, row, col - 1, coins, memo)});
        return memo[k][row][col];
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        const int ROWS = coins.size();
        const int COLS = coins[0].size();
        vector<vector<vector<int>>> memo(3, vector<vector<int>>(ROWS, vector<int>(COLS, -INF)));
        return f(2, ROWS - 1, COLS - 1, coins, memo);
    }
};