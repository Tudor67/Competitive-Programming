class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int>(n, 0));
        
        int val = 1, maxVal = n * n;
        int minRow = 0, maxRow = n - 1;
        int minCol = 0, maxCol = n - 1;
        while(val <= maxVal){
            for(int col = minCol; col <= maxCol; ++col){
                a[minRow][col] = val;
                val += 1;
            }
            for(int row = minRow + 1; row <= maxRow; ++row){
                a[row][maxCol] = val;
                val += 1;
            }
            for(int col = maxCol - 1; col >= minCol; --col){
                a[maxRow][col] = val;
                val += 1;
            }
            for(int row = maxRow - 1; row >= minRow + 1; --row){
                a[row][minRow] = val;
                val += 1;
            }
            minRow += 1; maxRow -= 1;
            minCol += 1; maxCol -= 1;
        }
        
        return a;
    }
};