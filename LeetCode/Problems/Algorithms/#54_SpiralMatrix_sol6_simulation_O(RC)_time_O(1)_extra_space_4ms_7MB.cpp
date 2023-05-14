class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        vector<int> res;
        res.reserve(ROWS * COLS);

        int topRow = 0;
        int bottomRow = ROWS - 1;
        int leftCol = 0;
        int rightCol = COLS - 1;
        while((int)res.size() < ROWS * COLS){
            for(int col = leftCol; col <= rightCol && topRow <= bottomRow; ++col){
                res.push_back(matrix[topRow][col]);
            }
            topRow += 1;

            for(int row = topRow; row <= bottomRow && leftCol <= rightCol; ++row){
                res.push_back(matrix[row][rightCol]);
            }
            rightCol -= 1;

            for(int col = rightCol; col >= leftCol && topRow <= bottomRow; --col){
                res.push_back(matrix[bottomRow][col]);
            }
            bottomRow -= 1;

            for(int row = bottomRow; row >= topRow && leftCol <= rightCol; --row){
                res.push_back(matrix[row][leftCol]);
            }
            leftCol += 1;
        }

        return res;
    }
};