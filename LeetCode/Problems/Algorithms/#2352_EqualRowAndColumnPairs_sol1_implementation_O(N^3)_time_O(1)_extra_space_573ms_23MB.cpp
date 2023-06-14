class Solution {
private:
    bool isEqual(vector<vector<int>>& grid, int row, int col){
        const int N = grid.size();
        for(int i = 0; i < N; ++i){
            if(grid[row][i] != grid[i][col]){
                return false;
            }
        }
        return true;
    }

public:
    int equalPairs(vector<vector<int>>& grid) {
        const int N = grid.size();

        int res = 0;
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < N; ++col){
                if(isEqual(grid, row, col)){
                    res += 1;
                }
            }
        }

        return res;
    }
};