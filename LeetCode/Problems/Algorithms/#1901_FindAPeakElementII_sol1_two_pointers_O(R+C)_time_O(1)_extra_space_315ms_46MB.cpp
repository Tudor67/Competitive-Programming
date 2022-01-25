class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        const int ROWS = mat.size();
        const int COLS = mat[0].size();
        
        int row = 0;
        int col = 0;
        while(true){
            bool updated = false;
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(mat[nextRow][nextCol] >= mat[row][col]){
                        row = nextRow;
                        col = nextCol;
                        updated = true;
                        break;
                    }
                }
            }
            if(!updated){
                break;
            }
        }
        
        return {row, col};
    }
};