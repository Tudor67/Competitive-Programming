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
            int prevObstacleRow = -1;
            int stones = 0;
            for(int row = 0; row <= RES_ROWS; ++row){
                if(row == RES_ROWS || res[row][col] == CellType::OBSTACLE){
                    for(int i = prevObstacleRow + 1; i < row; ++i){
                        res[i][col] = CellType::EMPTY;
                    }
                    for(int i = row - stones; i < row; ++i){
                        res[i][col] = CellType::STONE;
                    }
                    prevObstacleRow = row;
                    stones = 0;
                }else if(res[row][col] == CellType::STONE){
                    stones += 1;
                }
            }
        }

        return res;
    }
};