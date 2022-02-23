class Solution {    
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
            int row2 = ROWS - 1;
            for(int row1 = ROWS - 1; row1 >= 0; --row1){
                if(a[row1][col] == '*'){
                    row2 = row1 - 1;
                }else if(a[row1][col] == '#'){
                    swap(a[row1][col], a[row2][col]);
                    row2 -= 1;
                }
            }
        }
        
        return a;
    }
};