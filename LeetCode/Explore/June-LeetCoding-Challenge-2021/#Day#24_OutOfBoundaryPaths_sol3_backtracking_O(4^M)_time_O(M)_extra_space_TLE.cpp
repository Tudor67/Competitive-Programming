class Solution {
private:
    int countTotalPaths(int row, int col, int maxMove, const int& ROWS, const int& COLS, const int& MODULO) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        if(row == -1 || row == ROWS || col == -1 || col == COLS){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        int totalPaths = 0;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            totalPaths += countTotalPaths(nextRow, nextCol, maxMove - 1, ROWS, COLS, MODULO);
            totalPaths %= MODULO;
        }
        return totalPaths;
    }
    
public:
    int findPaths(int rows, int cols, int maxMove, int startRow, int startColumn) {
        static const int MODULO = 1e9 + 7;
        return countTotalPaths(startRow, startColumn, maxMove, rows, cols, MODULO);
    }
};