class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        vector<vector<unordered_set<int>>> balances(ROWS, vector<unordered_set<int>>(COLS));
        
        if(grid[0][0] == '('){
            balances[0][0] = {1};
        }

        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                for(int balance: balances[row][col]){
                    if(row + 1 < ROWS){
                        if(grid[row + 1][col] == '('){
                            balances[row + 1][col].insert(balance + 1);
                        }else if(balance >= 1){
                            balances[row + 1][col].insert(balance - 1);
                        }
                    }

                    if(col + 1 < COLS){
                        if(grid[row][col + 1] == '('){
                            balances[row][col + 1].insert(balance + 1);
                        }else if(balance >= 1){
                            balances[row][col + 1].insert(balance - 1);
                        }
                    }
                }
            }
        }

        return balances[ROWS - 1][COLS - 1].contains(0);
    }
};