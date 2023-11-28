class Solution {
private:
    const int MODULO = 1e9 + 7;
    const vector<pair<int, int>> DIRECTIONS = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                               {2, -1}, {2, 1}, {1, -2}, {1, 2}};

    int solve(int row, int col, int n, vector<vector<vector<int>>>& memo){
        if(row < 0 || 4 <= row || col < 0 || 3 <= col){
            return 0;
        }
        
        if(row == 3 && (col == 0 || col == 2)){
            return 0;
        }
        
        if(n == 1){
            return 1;
        }
        
        if(memo[row][col][n] != -1){
            return memo[row][col][n];
        }

        int res = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            res = (res + solve(nextRow, nextCol, n - 1, memo)) % MODULO;
        }

        memo[row][col][n] = res;
        return res;
    }

public:
    int knightDialer(int n) {
        vector<vector<vector<int>>> memo(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
        
        int res = 0;
        for(int row = 0; row <= 3; ++row){
            for(int col = 0; col <= 2; ++col){
                res = (res + solve(row, col, n, memo)) % MODULO;
            }
        }

        return res;
    }
};