class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int K = 3;

        set<int> sumsSet;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                sumsSet.insert(grid[row][col]);
                if((int)sumsSet.size() > K){
                    sumsSet.erase(sumsSet.begin());
                }

                int rowMaxLen = min(row + 1, ROWS - row);
                int colMaxLen = min(col + 1, COLS - col);
                int rhombusMaxLen = min(rowMaxLen, colMaxLen);

                for(int len = 2; len <= rhombusMaxLen; ++len){
                    int sum = grid[row - len + 1][col] + 
                              grid[row + len - 1][col];
                              
                    for(int i = 0; i < len - 1; ++i){
                        sum += grid[row - i][col - len + 1 + i] +
                               grid[row - i][col + len - 1 - i];
                    }
                    for(int i = 1; i < len - 1; ++i){
                        sum += grid[row + i][col - len + 1 + i] +
                               grid[row + i][col + len - 1 - i];
                    }

                    sumsSet.insert(sum);
                    if((int)sumsSet.size() > K){
                        sumsSet.erase(sumsSet.begin());
                    }
                }
            }
        }

        return vector<int>(sumsSet.rbegin(), sumsSet.rend());
    }
};