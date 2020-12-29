class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return {};
        }
        
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        const int SIZE = matrix.size() * matrix[0].size();
        
        vector<int> answer;
        int row = 0;
        int col = 0;
        while(answer.size() < SIZE){
            if((row + col) % 2 == 0){
                while(0 <= row && col < COLS){
                    answer.push_back(matrix[row][col]);
                    row -= 1;
                    col += 1;
                }
                row += 1;
                if(col == COLS){
                    row += 1;
                    col -= 1;
                }
            }else{
                while(row < ROWS && 0 <= col){
                    answer.push_back(matrix[row][col]);
                    row += 1;
                    col -= 1;
                }
                col += 1;
                if(row == ROWS){
                    row -= 1;
                    col += 1;
                }
            }
        }
        
        return answer;
    }
};