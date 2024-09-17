class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();

        int maxX = 0;
        int maxY = 0;
        for(const vector<int>& POINT: points){
            int x = POINT[0];
            int y = POINT[1];
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }

        const int ROWS = maxY + 1;
        const int COLS = maxX + 1;
        vector<vector<int>> grid(ROWS, vector<int>(COLS));
        for(const vector<int>& POINT: points){
            int x = POINT[0];
            int y = POINT[1];
            grid[maxY - y][x] = 1;
        }
        
        vector<vector<int>> prefSum = grid;
        for(int row = 1; row < ROWS; ++row){
            prefSum[row][0] += prefSum[row - 1][0];
        }

        for(int col = 1; col < COLS; ++col){
            prefSum[0][col] += prefSum[0][col - 1];
        }

        for(int row = 1; row < ROWS; ++row){
            for(int col = 1; col < COLS; ++col){
                prefSum[row][col] += prefSum[row - 1][col] + prefSum[row][col - 1] - prefSum[row - 1][col - 1];
            }
        }

        int validPairs = 0;
        for(int row1 = 0; row1 < ROWS; ++row1){
            for(int col1 = 0; col1 < COLS; ++col1){
                if(grid[row1][col1] == 0){
                    continue;
                }
                for(int row2 = row1; row2 < ROWS; ++row2){
                    for(int col2 = col1; col2 < COLS; ++col2){
                        if(grid[row2][col2] == 0){
                            continue;
                        }
                        int sum = prefSum[row2][col2];
                        if(row1 - 1 >= 0){
                            sum -= prefSum[row1 - 1][col2];
                        }
                        if(col1 - 1 >= 0){
                            sum -= prefSum[row2][col1 - 1];
                        }
                        if(row1 - 1 >= 0 && col1 - 1 >= 0){
                            sum += prefSum[row1 - 1][col1 - 1];
                        }
                        if(sum == 2){
                            validPairs += 1;
                        }
                    }
                }
            }
        }

        return validPairs;
    }
};