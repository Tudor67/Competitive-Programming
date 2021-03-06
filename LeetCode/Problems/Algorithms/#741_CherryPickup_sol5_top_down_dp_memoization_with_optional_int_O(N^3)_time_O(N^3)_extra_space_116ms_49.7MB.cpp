class Solution {
private:
    vector<vector<vector<optional<int>>>> memo;
    vector<vector<int>> grid;
    int N;
    
    bool isInside(int row, int col){
        return (0 <= row && row < N && 0 <= col && col < N);
    }
    
    int solve(int step, int row1, int row2){
        int col1 = step - row1;
        int col2 = step - row2;
        if(!isInside(row1, col1) || !isInside(row2, col2) || grid[row1][col1] == -1 || grid[row2][col2] == -1){
            return INT_MIN;
        }
        if(step == 0){
            return grid[0][0];
        }
        if(!memo[step][row1][row2].has_value()){
            int cherries = grid[row1][col1] + (row1 != row2 || col1 != col2) * grid[row2][col2];
            int opt1 = solve(step - 1, row1 - 1, row2 - 1);
            int opt2 = solve(step - 1, row1 - 1, row2);
            int opt3 = solve(step - 1, row1, row2 - 1);
            int opt4 = solve(step - 1, row1, row2);
            memo[step][row1][row2].emplace(cherries + max({opt1, opt2, opt3, opt4}));
        }
        return memo[step][row1][row2].value();
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        this->N = grid.size();
        
        memo.resize(2 * N - 1, vector<vector<optional<int>>>(N, vector<optional<int>>(N)));
        for(int step = 0; step < 2 * N - 1; ++step){
            for(int row1 = 0; row1 < N; ++row1){
                for(int row2 = 0; row2 < N; ++row2){
                    memo[step][row1][row2].reset();
                }
            }
        }
        
        return max(0, solve(2 * N - 2, N - 1, N - 1));
    }
};