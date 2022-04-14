class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        vector<vector<int>> a(N, vector<int>(N));
        
        int val = 1;
        int maxVal = N * N;
        
        int minRow = 0;
        int maxRow = N - 1;
        int minCol = 0;
        int maxCol = N - 1;
        
        while(val <= maxVal){
            for(int j = minCol; j <= maxCol && val <= maxVal; ++j){
                a[minRow][j] = val;
                val += 1;
            }
            minRow += 1;
            
            for(int i = minRow; i <= maxRow && val <= maxVal; ++i){
                a[i][maxCol] = val;
                val += 1;
            }
            maxCol -= 1;
            
            for(int j = maxCol; j >= minCol && val <= maxVal; --j){
                a[maxRow][j] = val;
                val += 1;
            }
            maxRow -= 1;
            
            for(int i = maxRow; i >= minRow && val <= maxVal; --i){
                a[i][minCol] = val;
                val += 1;
            }
            minCol += 1;
        }
        
        return a;
    }
};