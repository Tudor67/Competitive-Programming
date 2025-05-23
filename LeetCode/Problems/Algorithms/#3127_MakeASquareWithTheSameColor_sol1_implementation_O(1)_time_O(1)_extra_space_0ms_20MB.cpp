class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int row = 0; row + 1 < 3; ++row){
            for(int col = 0; col + 1 < 3; ++col){
                int blackCells = 0;
                for(int i = 0; i < 2; ++i){
                    for(int j = 0; j < 2; ++j){
                        blackCells += (int)(grid[row + i][col + j] == 'B');
                    }
                }
                if(blackCells != 2){
                    return true;
                }
            }
        }
        return false;
    }
};