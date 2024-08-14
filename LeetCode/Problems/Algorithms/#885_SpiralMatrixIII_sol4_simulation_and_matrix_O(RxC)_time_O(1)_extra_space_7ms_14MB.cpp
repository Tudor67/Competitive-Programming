class Solution {
private:
    void append(vector<vector<int>>& res, pair<int, int> pos, const int ROWS, const int COLS){
        int row = pos.first;
        int col = pos.second;
        if(0 <= row && row < ROWS && 0 <= col && col < COLS){
            res.push_back({row, col});
        }
    }

public:
    vector<vector<int>> spiralMatrixIII(int ROWS, int COLS, int rStart, int cStart) {
        vector<vector<int>> res;
        res.reserve(ROWS * COLS);

        int upRow = rStart;
        int downRow = rStart;
        int leftCol = cStart;
        int rightCol = cStart;
        while((int)res.size() < ROWS * COLS){
            rightCol = min(rightCol + 1, COLS);
            for(int col = leftCol; col <= rightCol && upRow >= 0; ++col){
                append(res, {upRow, col}, ROWS, COLS);
            }

            downRow = min(downRow + 1, ROWS);
            for(int row = upRow + 1; row <= downRow && rightCol < COLS; ++row){
                append(res, {row, rightCol}, ROWS, COLS);
            }

            leftCol = max(leftCol - 1, -1);
            for(int col = rightCol - 1; col >= leftCol && downRow < ROWS; --col){
                append(res, {downRow, col}, ROWS, COLS);
            }

            upRow = max(upRow - 1, -1);
            for(int row = downRow - 1; row >= upRow + 1 && leftCol >= 0; --row){
                append(res, {row, leftCol}, ROWS, COLS);
            }
        }

        return res;
    }
};