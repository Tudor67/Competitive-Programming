class Solution {
private:
    void updateCol(vector<vector<char>>& a, int col, int startRow, int endRow, int stones){
        for(int row = startRow; row <= endRow - stones; ++row){
            a[row][col] = '.';
        }
        for(int row = endRow - stones + 1; row <= endRow; ++row){
            a[row][col] = '#';
        }
    }
    
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const int ROWS = box[0].size();
        const int COLS = box.size();
        
        vector<vector<char>> a(ROWS, vector<char>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                a[row][col] = box[col][row];
            }
        }
        
        for(int row = 0; row < ROWS; ++row){
            for(int col1 = 0, col2 = COLS - 1; col1 < col2; ++col1, --col2){
                swap(a[row][col1], a[row][col2]);
            }
        }
        
        for(int col = 0; col < COLS; ++col){
            int stones = 0;
            int startRow = 0;
            for(int row = 0; row < ROWS; ++row){
                if(a[row][col] == '#'){
                    stones += 1;
                }else if(a[row][col] == '*'){
                    updateCol(a, col, startRow, row - 1, stones);
                    stones = 0;
                    startRow = row + 1;
                }
            }
            if(stones > 0){
                updateCol(a, col, startRow, ROWS - 1, stones);
            }
        }
        
        return a;
    }
};