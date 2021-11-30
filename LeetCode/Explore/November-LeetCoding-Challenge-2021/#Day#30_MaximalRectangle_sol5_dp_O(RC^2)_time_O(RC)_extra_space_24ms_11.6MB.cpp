class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();
        
        vector<vector<int>> h(ROWS, vector<int>(COLS));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(matrix[row][col] == '1'){
                    h[row][col] = 1;
                    if(row >= 1){
                        h[row][col] += h[row - 1][col];
                    }
                }
            }
        }
        
        int maxArea = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col1 = 0; col1 < COLS; ++col1){
                int minH = h[row][col1];
                for(int col2 = col1; col2 < COLS && minH >= 1; ++col2){
                    minH = min(minH, h[row][col2]);
                    int area = (col2 - col1 + 1) * minH;
                    maxArea = max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
};