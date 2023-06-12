class Solution {
private:
    int computeLength(int num){
        int len = 0;
        if(num <= 0){
            len = 1;
        }

        while(num != 0){
            len += 1;
            num /= 10;
        }
        
        return len;
    }

public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        vector<int> res(COLS);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                res[col] = max(res[col], computeLength(grid[row][col]));
            }
        }
        
        return res;
    }
};