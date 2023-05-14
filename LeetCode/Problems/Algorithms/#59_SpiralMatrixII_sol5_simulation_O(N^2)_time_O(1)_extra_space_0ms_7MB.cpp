class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const int ROWS = n;
        const int COLS = n;

        vector<vector<int>> res(ROWS, vector<int>(COLS));
        
        int val = 1;
        int topRow = 0;
        int bottomRow = ROWS - 1;
        int leftCol = 0;
        int rightCol = COLS - 1;
        while(val <= ROWS * COLS){
            for(int col = leftCol; col <= rightCol && topRow <= bottomRow; ++col){
                res[topRow][col] = val;
                val += 1;
            }
            topRow += 1;

            for(int row = topRow; row <= bottomRow && leftCol <= rightCol; ++row){
                res[row][rightCol] = val;
                val += 1;
            }
            rightCol -= 1;

            for(int col = rightCol; col >= leftCol && topRow <= bottomRow; --col){
                res[bottomRow][col] = val;
                val += 1;
            }
            bottomRow -= 1;

            for(int row = bottomRow; row >= topRow && leftCol <= rightCol; --row){
                res[row][leftCol] = val;
                val += 1;
            }
            leftCol += 1;
        }

        return res;
    }
};