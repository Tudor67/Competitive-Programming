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
            rightCol += 1;
            for(int col = leftCol; col <= rightCol; ++col){
                append(res, {upRow, col}, ROWS, COLS);
            }

            downRow += 1;
            for(int row = upRow + 1; row <= downRow; ++row){
                append(res, {row, rightCol}, ROWS, COLS);
            }

            leftCol -= 1;
            for(int col = rightCol - 1; col >= leftCol; --col){
                append(res, {downRow, col}, ROWS, COLS);
            }

            upRow -= 1;
            for(int row = downRow - 1; row >= upRow + 1; --row){
                append(res, {row, leftCol}, ROWS, COLS);
            }
        }

        return res;
    }
};