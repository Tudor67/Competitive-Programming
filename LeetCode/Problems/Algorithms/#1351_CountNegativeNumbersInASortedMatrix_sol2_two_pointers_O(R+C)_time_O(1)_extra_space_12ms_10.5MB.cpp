class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        int answer = 0;
        int row = 0;
        int col = COLS - 1;
        while(row < ROWS && 0 <= col){
            if(grid[row][col] < 0){
                col -= 1;
            }else{
                answer += (COLS - 1 - col);
                row += 1;
            }
        }
        
        answer += (ROWS - row) * (COLS - 1 - col);
        
        return answer;
    }
};