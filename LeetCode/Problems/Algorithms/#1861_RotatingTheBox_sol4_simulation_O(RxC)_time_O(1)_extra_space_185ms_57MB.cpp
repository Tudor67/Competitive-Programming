class Solution {
private:
    enum CellType { STONE = '#', OBSTACLE = '*', EMPTY = '.' };

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int RES_ROWS = box[0].size();
        const int RES_COLS = box.size();

        // the box is rotated 90 degrees clockwise
        vector<vector<char>> res(RES_ROWS, vector<char>(RES_COLS));
        for(int row = 0; row < RES_ROWS; ++row){
            for(int col = 0; col < RES_COLS; ++col){
                res[row][col] = box[col][row];
            }
        }

        for(int row = 0; row < RES_ROWS; ++row){
            reverse(res[row].begin(), res[row].end());
        }

        // each stone falls down until it lands on an obstacle
        for(int col = 0; col < RES_COLS; ++col){
            int row2 = RES_ROWS - 1;
            for(int row1 = RES_ROWS - 1; row1 >= 0; --row1){
                if(res[row1][col] == CellType::STONE){
                    swap(res[row1][col], res[row2][col]);
                    row2 -= 1;
                }else if(res[row1][col] == CellType::OBSTACLE){
                    row2 = row1 - 1;
                }
            }
        }

        return res;
    }
};