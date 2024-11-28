class Solution {
private:
    enum CellType { STONE = '#', OBSTACLE = '*', EMPTY = '.' };

public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int BOX_ROWS = box.size();
        const int BOX_COLS = box[0].size();

        // the box is rotated 90 degrees clockwise
        // each stone falls down until it lands on an obstacle
        vector<vector<char>> res(BOX_COLS, vector<char>(BOX_ROWS));
        for(int row = 0; row < BOX_ROWS; ++row){
            int col2 = BOX_COLS - 1;
            for(int col1 = BOX_COLS - 1; col1 >= 0; --col1){
                if(box[row][col1] == CellType::OBSTACLE){
                    res[col1][BOX_ROWS - 1 - row] = CellType::OBSTACLE;
                    col2 = col1 - 1;
                }else if(box[row][col1] == CellType::STONE){
                    res[col1][BOX_ROWS - 1 - row] = CellType::EMPTY;
                    res[col2][BOX_ROWS - 1 - row] = CellType::STONE;
                    col2 -= 1;
                }else{
                    res[col1][BOX_ROWS - 1 - row] = CellType::EMPTY;
                }
            }
        }

        return res;
    }
};