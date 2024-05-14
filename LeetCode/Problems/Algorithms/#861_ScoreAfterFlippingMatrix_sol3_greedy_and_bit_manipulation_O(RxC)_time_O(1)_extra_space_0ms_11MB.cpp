class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxScore = ROWS << (COLS - 1);
        for(int col = 1; col < COLS; ++col){
            int colOnes = 0;
            for(int row = 0; row < ROWS; ++row){
                colOnes += (grid[row][0] == grid[row][col]);
            }
            maxScore += max(colOnes, ROWS - colOnes) << (COLS - 1 - col);
        }

        return maxScore;
    }
};